#include "test.cuh"

__global__ void cuda_lanch_add(float *ptr, const int len)
{
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    
    int stride = blockDim.x * gridDim.x;
    for(int i = index; i < len; i = i + stride)
    {
        if(i < len){
            ptr[i] = ptr[i] * 2;
        }
    }
}


void add(float *ptr, const int len)
{
    dim3 blockSize(256);
    dim3 gridSize(10);
    cuda_lanch_add<<<gridSize, blockSize>>>(ptr, len);
}