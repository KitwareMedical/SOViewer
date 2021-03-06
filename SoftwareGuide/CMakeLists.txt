#####################################################
#
#   This is the root SoftwareGuide CMakeLists file.
#
#####################################################
#
# To Build the SOV Software Guide,
# 
# Compile and build the SOV binaries. You will need to build the Examples in 
# the Insight directory with the CMakeLists.txt file in Insight/
#
# Run this CMakeLists.txt file and set BUILD_FIGURES  'ON'. Specify the 
# directory containing the Insight executables. Specify SOV data paths.
# The default data path inferred is Insight/Examples/Data. This should suffice
# for building the SoftwareGuide. Should more paths be need add them in a colon
# seperated list. 
#
# Make
# Make
# 
# More than one make may be necessary to ensure generation of the index
# 
# If BUILD_FIGURES is set to ON, the examples source files are parsed for 
# command line argument tags and if found executed to generate output 
# images, if not the images are expected to be present in the Art/ folder
# in PNG/XFIG/JPEG/EPS format. 
# 
# Since generating figures may take a while, you may set BUILD_FIGURES to 
# OFF. In this case, all figures are expected to be present in the Art/
# folder in PNG/XFIG/JPEG/EPS format. 
#  
#
CMAKE_MINIMUM_REQUIRED(VERSION 1.6)

PROJECT(SoftwareGuide C)



#
# File that defines the path to .cxx examples in SOV sources
#
CONFIGURE_FILE(
${SoftwareGuide_SOURCE_DIR}/SoftwareGuideConfiguration.tex.in 
${SoftwareGuide_BINARY_DIR}/SoftwareGuideConfiguration.tex
IMMEDIATE
)

# Find SOV Sources
FIND_PATH(SOV_SOURCE_DIR UseSOV.cmake
   ../SOViewer
   ../../SOViewer
   ../../../SOViewer
   ../../../../SOViewer
   ../../../../../SOViewer
   ../../../../../../SOViewer
  )

IF( NOT SOV_SOURCE_DIR )
  MESSAGE(FATAL_ERROR "SOV source directory is not set")
ENDIF( NOT SOV_SOURCE_DIR )

# SOV_DATA_PATHS is searched recursively.. you need not enter sub-directories
SET(SOV_DATA_PATHS "${SOV_SOURCE_DIR}/Examples/Data" CACHE STRING "Where the SOV data is. Enter a colon seperated list.")

#
# Rebuild the Software Guide figures or not ?
SET(BUILD_FIGURES ON CACHE BOOL "Build Software Guide figures")
IF( BUILD_FIGURES )
  SET(SOV_EXECUTABLES_DIR "" CACHE PATH "Where the SOV examples executables are")
  SET(RUN_EXAMPLES_SCRIPT "${SoftwareGuide_SOURCE_DIR}/Examples/RunExamples.pl" CACHE FILEPATH "Where the RunExamples Script is")
ENDIF( BUILD_FIGURES )


# 
# Find ImageMagick tools
# This is used to convert image formats
#
INCLUDE (${CMAKE_ROOT}/Modules/FindImageMagick.cmake)
IF(NOT IMAGEMAGICK_CONVERT_EXECUTABLE)
  MESSAGE("ImageMagick convert utility was not found. Please pass to advanced mode and provide its full path")
ENDIF(NOT IMAGEMAGICK_CONVERT_EXECUTABLE)

  SUBDIRS(Art)
  SUBDIRS(Examples)
  SUBDIRS(Latex)

# 
# Examples Directory is where .cxx files are converted 
# into .tex by a perl script.
#
# Art Directory with images and diagrams
#
# Latex Directory with tex files 
#
