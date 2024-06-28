# rMSI2
rMSI2 is an R package for mass spectrometry (MS) imaging data handling and visualization.
The package is a multi-platform tool that has been tested on Linux, MAC and Windows systems. 
It provides an optimized data model to allow loading large MS imaging datasets in low resource computers. MS data is stored in the hard disk drive (HDD) but rMSI2 is able to access data as if it where kept in computer’s memory using a virtual memory technology. The package also provides a graphical user interface (GUI) to facilitate MS imaging data exploration in R platform. The main rMSI2 GUI allows representing up to three MS ions spacial distribution, direct access to pixel spectrum and other usefull features. See and screenshot below.

![alt text](https://github.com/prafols/rMSI2/blob/main/images/screenShotrMSI_RGB.png "rMSI2 Main GUI")

### Installation
Check out the installation guide at:  [installation guide](https://github.com/prafols/rMSI2/blob/main/guides/installation.md "Install rMSI2")

### Quick Start Guide
This guide provides a quick overview of rMSI2 package usage. Before going through this guide it is recommended to have some knowledge of R language (<https://www.r-project.org>) and  rMSI2 package installed as described above. The fundamentals of rMSI2 are described here but for a more detailed information, please check the package documentation through the standard R help interface:
```R
> ??rMSI2
```
A more comprehensive workshop of rMSI2 in use is available at: [rMSI2 Workshop](https://github.com/prafols/rMSI2/blob/main/guides/rMSI2_workshop.Rmd "rMSI2 workshop")

##### Loading data and starting the main GUI
The first step to start using rMSI2 consists in loading an MS image. You can obtain some example data to test the program at the public available links in  **Example Data** section below. The MS imaging data can be loaded from two formats: rMSI2 format and imzML (currently only continuous mode is supported). It is also possible to load data from Bruker’s XMASS format but this format has to be previously converted using the *importBrukerXMASSImg_Wizard()* function.
The more straightforward way of loading data is using the function *OpenMSI()* which prompts the user to graphically select up to two MS images to load:
```R
myData <- rMSI2::OpenMSI()
```
This function will load the images and open the main graphical user interface (GUI) which allows exploring the MS data interactively.
The returned value of *OpenMSI()* will contain a list of two images where: myData$img1 corresponds to the first user-selected image and myData$img2 the second loaded images. However, it is not mandatory to load two images. If only one image is loaded, then the other one will be *NULL*.

Nevertheless, opening the main GUI each time a MS images is loaded may not be very convenient in some cases. So, another way of loading data is using the *LoadMsiData()* function:
```R
myData <- rMSI2::LoadMsiData("/path/to/your/image_data.imzML")
```
Where the path to the image must be complete including .imzML or .tar extension. Then, this function will return the loaded MS image in a rMSI2 formatted R object.
The main GUI can be started anytime using the *MSIWindow()* function. For eaxmple:
```R
rMSI2::MSIWindow(myData)
```
When rMSI2 uncompresse MS imaging data from its own format (.tar) or imzML format a folder called something like "ramdisk_yourData" is created at the same place where your data is stored on your hard drive. This folder will be used for rMSI2 to access MS data from the hard drive inside your R ression.
If an MS image was previously loaded, rMSI2 will automatically locate the “ramdisk” folder and another day, in another R session *OpenMSI()* and *LoadMsiData()* function will use that ramdisk directory to restore the data in a few seconds. You can also delete this ramdisk folder (for example to recuperate some HDD space) and then it will be recreated when you call rMSI2 loading functions.

##### rMSI2 data structure
MS images are loaded into R using rMSI2 format which consists in a list with the following fields:
```R
name: A string with the name of the MS image.
mass: A numeric vector with all the mass channels.
Size: A named two element vector containing the X and Y size of image in pixels.
pos:  A two column matrix where each rows provides the raster location of each spectrum.
pixel_size_um: The pixel size in microns.
mean: The average spectrum of the whole image.
data: Data pointers to image spectra actually stored in the hard drive.
normalizations: A list containing intensity normalization coefficients already computed and stored.
```
Each one of the elements in the MS image can be access directly using the $ operator. For example, to obtain the pixel resolution:
```R
myData$pixel_size_um
```
rMSI2 stores MS data in computer’s hard drive and only loads part of it to RAM when it is required. For example, the main GUI only will load parts of spectra to memory to render an ion image, but the whole data won't be never completely loaded. Each MS spectrum is located using a unique identifier (ID) which is actually an integer number. The raster position of each spectrum is stored in myData$pos array where each row number corresponds to the spectrum ID of each raster position. 

##### Accessing spectra
To simplify data access rMSI2 provides *loadImgCunckFromIds()* and *loadImgCunckFromCoords()* functions to load a bunch of selected pixel spectra to an R matrix. This functions load data into standard R variables so, be careful to not load to many data in your computer’s memory. For example, lets suppose I want lo load some spectra of pixels which I know their ID and the desired ID’s are 34, 56 and 96:
```R
mySpectra <- rMSI2::loadImgChunkFromIds(myData, c(34, 56, 96))
```
And if I don't know the ID's but I know the XY coordinates the spectra can be also access expresing the XY coordinates as complex numbers, for example:
```R
mySpectra <- rMSI2::loadImgChunkFromCoords(myData, complex(real = c(10, 12, 34), imaginary = c(5, 9, 12)))
```
In both cases an R matrix is returned. Each row of the matrix corresponds to one spectrum using the same order as the ID’s or XY coords were provided. So you can get your first spectrum intensities by doing:
```R
myFirstIntensities <- mySpectra[1, ]
```
The mass axis is common to the whole image and is available at mass field: *myData$mass*.  This spectrum can be plotted using the rMSI2 spectra viewer GUI:
```R
rMSI2::plotSpectra(mass = myData$mass, intensity = myFirstIntensities, col = "red")
```
The rMSI2 main GUI can be used to obtain spectra ID’s from a set of pixels. First, open the MS image in the main GUI using the  *OpenMSI()* or *MSIWindow()* functions as described before. Then select some ion to visualize in the spectrum. After that, draw a rectangle over the MS image and click the *Get Spectra* button to fill the spectra list with the pixels inside the selected area. Finally, export the spectra list using the *Export* button. This will export the selected spectra as plain ASCII files and a list of ID’s also as an ASCII file. If many pixels are selected a warning will be displayed and exporting only ID list will be allowed. Then, the exported list can be loaded into R session by standard functions as *read.table()*.

###  Example Data
Some MS images are available at the following link to test rMSI2 package:
TODO add some example data in imzML format
