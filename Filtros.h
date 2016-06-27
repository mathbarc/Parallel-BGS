#ifndef FILTROS_H
#define FILTROS_H 1
#include <cuda_runtime.h>
#include <device_launch_parameters.h>



__global__
void gaussian_blur(const unsigned char* const inputChannel,
                   unsigned char* const outputChannel,
                   int numRows, int numCols,
                   const float* const filter, const int filterWidth);

__global__
void rgba_to_greyscale(const uchar4* const rgbaImage,
                       unsigned char* const greyImage,
                       int numRows, int numCols);


void trataImagem(const unsigned char* imgin, const unsigned char* imgout, int cols, int rows);
#endif
