#include <cuda_runtime_api.h>

extern "C"
{
    void add(const float *ptr, const int len);
}