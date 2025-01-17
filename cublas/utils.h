#ifndef UTILS_H_
#define UTILS_H_

#define CUDA_CALL(x) do { if((x) != cudaSuccess) { \
        printf("Error at %s:%d, %d\n", __FILE__, __LINE__, EXIT_FAILURE); \
        exit(EXIT_FAILURE);}} while(0)

#define CUBLAS_CALL(x) do { if((x) != CUBLAS_STATUS_SUCCESS) { \
        printf("Error %d at %s:%d, %d\n", x, __FILE__, __LINE__, EXIT_FAILURE); \
        exit(EXIT_FAILURE);}} while(0)

#define CUDNN_CALL(x) do { if((x) != CUDNN_STATUS_SUCCESS) { \
        printf("Error at %s:%d, %d\n", __FILE__, __LINE__, EXIT_FAILURE); \
        exit(EXIT_FAILURE);}} while(0)

#define CURAND_CALL(x) do { if((x) != CURAND_STATUS_SUCCESS) { \
        printf("Error at %s:%d, %d\n", __FILE__, __LINE__, EXIT_FAILURE); \
        exit(EXIT_FAILURE);}} while(0)

#include <sys/time.h>
#include <ctime>
#include <curand.h>
#include <cstdio>

double get_durtime(struct timeval beg, struct timeval end);

//void rand_gen_data(float* des, int num_of_elems);

static int DTYPE_FLOAT = 0;
static int DTYPE_HALF = 1;

#endif
