#include <iostream>
#include <vector>
#include <iterator>
#include "test.cuh"

int main(int argc, char **argv)
{
    std::vector<float> data{1,2,3,4,5};

    float *dev_ptr;
    cudaMalloc((void**)&dev_ptr, data.size() * sizeof(float));
    cudaMemcpy(dev_ptr, (void*)data.data(), data.size() * sizeof(float), cudaMemcpyHostToDevice);

    add(dev_ptr, data.size());

    cudaMemcpy((void**)data.data(), dev_ptr, data.size() * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(dev_ptr);

    std::copy(data.begin(), data.end(), std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}