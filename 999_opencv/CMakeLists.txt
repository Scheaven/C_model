cmake_minimum_required(VERSION 2.8)
project( ImageAutoRotate )
find_package( OpenCV REQUIRED )
add_executable( ImageAutoRotate ImageAutoRotate.cpp )
target_link_libraries( ImageAutoRotate ${OpenCV_LIBS} )

