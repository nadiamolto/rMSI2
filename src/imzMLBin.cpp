/*************************************************************************
 *     rMSI - R package for MSI data processing
 *     Copyright (C) 2019 Pere Rafols Soler
 * 
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************/

#include "imzMLBin.h"
#include <stdexcept>
#include <Rcpp.h>

//#define __DEBUG__

ImzMLBin::ImzMLBin(const char* ibd_fname, imzMLDataType mzType, imzMLDataType intType):
  mzDataType(mzType), intDataType(intType)
{
  switch(mzDataType)
  {
    case int32: 
    case float32:  
      mzDataPointBytes = 4;
      break;
      
    case int64:
    case float64:
      mzDataPointBytes = 8;
      break;

    default:
      throw std::runtime_error("ERROR: ImzMLBin class constructor: invalid mzType ");
      break;
  }
  
  switch(intType)
  {
    case int32: 
    case float32:  
      intDataPointBytes = 4;
      break;
      
    case int64:
    case float64:
      intDataPointBytes = 8;
      break;
      
    default:
      throw std::runtime_error("ERROR: ImzMLBin class constructor: invalid intType.\n");
      break;
  }
  
#ifdef __DEBUG__
Rcpp::Rcout << "ImzMLBin() constructor end successfuly\n";
#endif
}

ImzMLBin::~ImzMLBin()
{
#ifdef __DEBUG__
  Rcpp::Rcout << "ImzMLBin() destructor start...";
#endif
  if(ibdFile.is_open())
  {
    ibdFile.close();
#ifdef __DEBUG__
    Rcpp::Rcout << "ibdFile closed...";
#endif
  }
  
#ifdef __DEBUG__
  Rcpp::Rcout << "ImzMLBin() destructor end successfuly\n";
#endif
}

template<typename T> 
void ImzMLBin::covertBytes2Double(char* inBytes, double* outPtr, unsigned int N)
{
  //First, copy the data to an intermediate vector with the desired type
  T* auxBuffer = new T[N];
  memcpy(auxBuffer, inBytes, sizeof(T)*N);
  
  //Finally, move the data to the double pointer
  for(int i = 0; i < N; i++)
  {
    outPtr[i] = (double)auxBuffer[i];
  }
  
  delete[] auxBuffer;
}

ImzMLBinRead::ImzMLBinRead(const char* ibd_fname, imzMLDataType mzType, imzMLDataType intType) :
  ImzMLBin(ibd_fname, mzType, intType)
{
#ifdef __DEBUG__
  Rcpp::Rcout << "ImzMLBinRead() constructor start...";
#endif
  ibdFile.open(ibd_fname, std::fstream::in | std::ios::binary);
  if(!ibdFile.is_open())
  {
    throw std::runtime_error("ERROR: ImzMLBinRead could not open the imzML ibd file.\n"); 
  }
#ifdef __DEBUG__
  Rcpp::Rcout << "ImzMLBinRead() constructor end successfuly\n";
#endif
}

ImzMLBinRead::~ImzMLBinRead()
{
  //Empty desctructor
}

void ImzMLBinRead::readMzData(unsigned long offset, unsigned int N, double* ptr )
{
  unsigned int byteCount = N*mzDataPointBytes;
  char* buffer = new char [byteCount];
  ibdFile.seekg(offset);
  ibdFile.read (buffer, byteCount);
  
  switch(mzDataType)
  {
    case int32:
      covertBytes2Double<int>(buffer, ptr, N);
      break;
      
    case float32:  
      covertBytes2Double<float>(buffer, ptr, N);
      break;
  
    case int64:
      covertBytes2Double<long>(buffer, ptr, N);
      break;
      
    case float64:
      //covertBytes2Double<double>(buffer, ptr, N); If double there is no need of intermediate conversion
      memcpy(ptr, buffer, sizeof(double)*N);
      break;
  }
  
  delete[] buffer;
}

void ImzMLBinRead::readIntData(unsigned long offset, unsigned int N, double* ptr )
{
  unsigned int byteCount = N*mzDataPointBytes;
  char* buffer = new char [byteCount];
  ibdFile.seekg(offset);
  ibdFile.read (buffer, byteCount);
  
  switch(intDataType)
  {
  case int32:
    covertBytes2Double<int>(buffer, ptr, N);
    break;
    
  case float32:  
    covertBytes2Double<float>(buffer, ptr, N);
    break;
    
  case int64:
    covertBytes2Double<long>(buffer, ptr, N);
    break;
    
  case float64:
    //covertBytes2Double<double>(buffer, ptr, N); If double there is no need of intermediate conversion
    memcpy(ptr, buffer, sizeof(double)*N);
    break;
  }
  
  delete[] buffer;
}

ImzMLBinWrite::ImzMLBinWrite(const char* ibd_fname, imzMLDataType mzType, imzMLDataType intType) :
  ImzMLBin(ibd_fname, mzType, intType)
{
  
  ibdFile.open(ibd_fname, std::fstream::out | std::ios::binary); //TODO do I want ot truncate the file or just modify it?
  if(!ibdFile.is_open())
  {
    throw std::runtime_error("Error: ImzMLBinRead could not open the imzML ibd file.\n");
  }
}

ImzMLBinWrite::~ImzMLBinWrite()
{
  //Empty desctructor
}   

void ImzMLBinWrite::writeMzData(unsigned long offset, unsigned int N, double* ptr )
{
  //TODO checkout fstream doc: http://www.cplusplus.com/reference/fstream/fstream/
  // seek operation is diferent to the ifstream!
    throw std::runtime_error("TODO: Not implemented yet, sorry :(");
}

void ImzMLBinWrite::writeIntData(unsigned long offset, unsigned int N, double* ptr )
{
  //TODO checkout fstream doc: http://www.cplusplus.com/reference/fstream/fstream/
  // seek operation is diferent to the ifstream!
  throw std::runtime_error("TODO: Not implemented yet, sorry :(");
}

///DEBUG METHODS////////////////////////////////////////////////////////////////////////

//' Testing the imzMLreader
//' testingimzMLBinRead
//' @param ibdFname: full path to the ibd file.
//' @param N: number of elemetns (or data point to read).
//' @param offset: offset in bytes at which the reading operation is started.
//' @param read_mz: if true m/z data is readed, otherwise intensities are readed.
// [[Rcpp::export(name=".debug_imzMLBinReader")]]
Rcpp::NumericVector testingimzMLBinRead(const char* ibdFname, unsigned int N, unsigned long offset, Rcpp::String dataTypeString, bool read_mz)
{
  Rcpp::NumericVector x(N);
  imzMLDataType mdatatype;
  
  if(dataTypeString == "int")
  {
    mdatatype = imzMLDataType::int32;
  }
  else if(dataTypeString == "long")
  {
    mdatatype = imzMLDataType::int64;
  }
  else if(dataTypeString == "float")
  {
    mdatatype = imzMLDataType::float32;
  }
  else if(dataTypeString == "double")
  {
    mdatatype = imzMLDataType::float64;
  }
  else
  {
    throw std::runtime_error("Error: invalid dataTypeString");
  }
  
  try
  {
    ImzMLBinRead myReader(ibdFname, mdatatype, mdatatype);
    if(read_mz)
    {
      myReader.readMzData(offset, N, x.begin());  
    }
    else
    {
      myReader.readIntData(offset, N, x.begin());
    }
    
  }
  catch(std::runtime_error &e)
  {
    Rcpp::Rcout << "Catch Error: "<< e.what() << "\n";
  }
  
  return x;
}