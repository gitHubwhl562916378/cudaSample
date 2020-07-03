cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(CudaSaple
        LANGUAGES CXX CUDA
        VERSION "1.0"
        DESCRIPTION "cuda sample"
        HOMEPAGE_URL "none")

add_compile_options(-std=c++11)
include_directories(
    ${CUDA_TOOLKIT_ROOT_DIR}/include
)

add_executable(${PROJECT_NAME} test.cu test.cuh main.cpp)
target_link_libraries(${PROJECT_NAME} ${CUDA_LIBRARIES})