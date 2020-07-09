cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(CudaSaple
        LANGUAGES CXX CUDA
        VERSION "1.0"
        DESCRIPTION "cuda sample"
        HOMEPAGE_URL "none")

find_package(CUDA REQUIRED)
add_compile_options(-std=c++11)
include_directories(
    # ${CUDA_TOOLKIT_ROOT_DIR}/include
    ${CUDA_INCLUDE_DIRS}
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_AVCODEC REQUIRED IMPORTED_TARGET libavcodec)
message(${PC_AVCODEC_INCLUDE_DIRS})
message(${PC_AVCODEC_LIBDIR})
message(${PC_AVCODEC_LIBRARIES})
#、通过本机安装的pkg-config程序来查找依赖库的库路径和头文件路径
#、搜索方法为使用pkg-config查找库安装时的.pc文件,libavcodec为pc文件名，该文件记录了库路径、依赖、头文件路径等信息
#、pkg-config搜索.pc文件的路径可用pkg-config  --variable pc_path pkg-config查看
#、可将安装好的三方库的.pc文件复制到搜索路径，也可以使用export PKG_CONFIG_PATH添加搜索路径
#、查找成功后第一个参数变量加上_INCLUDE_DIRS是头文件路径，加上_LIBDIR或者_LIBRARY_DIRS是库文件路径(具体可以看pc文件内容)
#     加上_LIBRARIES是库名可用于target_link_libraries

find_library(FUZZY NAMES opencv_cudaoptflow opencv_fuzzy HINTS /usr/local/opencv-4.3.0/lib) 
message(${FUZZY})
#、在/usr/local/opencv-4.3.0/lib目录下查找opencv_cudaoptflow
#、opencv_fuzzy为前缀的库文件,以找到的第一个为结束返回，返回的库全路径名在变量FUZZY中
#、搜索路径先是/usr/local/opencv-4.3.0/lib然后是其后面的default路径，不填的话就是CMAKE_LIBRARY_PATH

add_executable(${PROJECT_NAME} test.cu test.cuh main.cpp)
target_link_libraries(${PROJECT_NAME} ${CUDA_CUDA_LIBRARY})