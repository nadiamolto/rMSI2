// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// CparseBrukerXML
List CparseBrukerXML(String xml_path);
RcppExport SEXP _rMSI_CparseBrukerXML(SEXP xml_pathSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< String >::type xml_path(xml_pathSEXP);
    rcpp_result_gen = Rcpp::wrap(CparseBrukerXML(xml_path));
    return rcpp_result_gen;
END_RCPP
}
// testingimzMLBinRead
Rcpp::NumericVector testingimzMLBinRead(const char* ibdFname, unsigned int NPixels, unsigned int N, unsigned long offset, Rcpp::String dataTypeString, bool read_mz, bool continuous);
RcppExport SEXP _rMSI_testingimzMLBinRead(SEXP ibdFnameSEXP, SEXP NPixelsSEXP, SEXP NSEXP, SEXP offsetSEXP, SEXP dataTypeStringSEXP, SEXP read_mzSEXP, SEXP continuousSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const char* >::type ibdFname(ibdFnameSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type NPixels(NPixelsSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type N(NSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type offset(offsetSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type dataTypeString(dataTypeStringSEXP);
    Rcpp::traits::input_parameter< bool >::type read_mz(read_mzSEXP);
    Rcpp::traits::input_parameter< bool >::type continuous(continuousSEXP);
    rcpp_result_gen = Rcpp::wrap(testingimzMLBinRead(ibdFname, NPixels, N, offset, dataTypeString, read_mz, continuous));
    return rcpp_result_gen;
END_RCPP
}
// CimzMLParse
List CimzMLParse(String xml_path);
RcppExport SEXP _rMSI_CimzMLParse(SEXP xml_pathSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< String >::type xml_path(xml_pathSEXP);
    rcpp_result_gen = Rcpp::wrap(CimzMLParse(xml_path));
    return rcpp_result_gen;
END_RCPP
}
// CimzMLStore
bool CimzMLStore(String fname, List imgInfo);
RcppExport SEXP _rMSI_CimzMLStore(SEXP fnameSEXP, SEXP imgInfoSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< String >::type fname(fnameSEXP);
    Rcpp::traits::input_parameter< List >::type imgInfo(imgInfoSEXP);
    rcpp_result_gen = Rcpp::wrap(CimzMLStore(fname, imgInfo));
    return rcpp_result_gen;
END_RCPP
}
// MergeMassAxis
List MergeMassAxis(NumericVector mz1, NumericVector mz2);
RcppExport SEXP _rMSI_MergeMassAxis(SEXP mz1SEXP, SEXP mz2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type mz1(mz1SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type mz2(mz2SEXP);
    rcpp_result_gen = Rcpp::wrap(MergeMassAxis(mz1, mz2));
    return rcpp_result_gen;
END_RCPP
}
// ReduceDataPointsC
List ReduceDataPointsC(NumericVector mass, NumericVector intensity, double massMin, double massMax, int npoints);
RcppExport SEXP _rMSI_ReduceDataPointsC(SEXP massSEXP, SEXP intensitySEXP, SEXP massMinSEXP, SEXP massMaxSEXP, SEXP npointsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type mass(massSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type intensity(intensitySEXP);
    Rcpp::traits::input_parameter< double >::type massMin(massMinSEXP);
    Rcpp::traits::input_parameter< double >::type massMax(massMaxSEXP);
    Rcpp::traits::input_parameter< int >::type npoints(npointsSEXP);
    rcpp_result_gen = Rcpp::wrap(ReduceDataPointsC(mass, intensity, massMin, massMax, npoints));
    return rcpp_result_gen;
END_RCPP
}
// Ccreate_rMSIXBinData
Rcpp::List Ccreate_rMSIXBinData(Rcpp::List rMSIobj);
RcppExport SEXP _rMSI_Ccreate_rMSIXBinData(SEXP rMSIobjSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type rMSIobj(rMSIobjSEXP);
    rcpp_result_gen = Rcpp::wrap(Ccreate_rMSIXBinData(rMSIobj));
    return rcpp_result_gen;
END_RCPP
}
// testingLodepng
void testingLodepng();
RcppExport SEXP _rMSI_testingLodepng() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    testingLodepng();
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_rMSI_CparseBrukerXML", (DL_FUNC) &_rMSI_CparseBrukerXML, 1},
    {"_rMSI_testingimzMLBinRead", (DL_FUNC) &_rMSI_testingimzMLBinRead, 7},
    {"_rMSI_CimzMLParse", (DL_FUNC) &_rMSI_CimzMLParse, 1},
    {"_rMSI_CimzMLStore", (DL_FUNC) &_rMSI_CimzMLStore, 2},
    {"_rMSI_MergeMassAxis", (DL_FUNC) &_rMSI_MergeMassAxis, 2},
    {"_rMSI_ReduceDataPointsC", (DL_FUNC) &_rMSI_ReduceDataPointsC, 5},
    {"_rMSI_Ccreate_rMSIXBinData", (DL_FUNC) &_rMSI_Ccreate_rMSIXBinData, 1},
    {"_rMSI_testingLodepng", (DL_FUNC) &_rMSI_testingLodepng, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_rMSI(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
