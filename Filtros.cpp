#include "Filtros.h"
__global__
void gaussian_blur(const unsigned char* const inputChannel,
                   unsigned char* const outputChannel,
                   int numRows, int numCols,
                   const float* const filter, const int filterWidth)
{

    const int x =  blockIdx.x * blockDim.x + threadIdx.x;
    const int y =  blockIdx.y * blockDim.y + threadIdx.y;
    const int m = y * numCols + x;
    
    if(x >= numCols || y >= numRows)
         return;
    
    float color = 0.0f;
    
    for(int f_y = 0; f_y < filterWidth; f_y++) {
        for(int f_x = 0; f_x < filterWidth; f_x++) {
   
            int c_x = x + f_x - filterWidth/2;
            int c_y = y + f_y - filterWidth/2;
            c_x = min(max(c_x, 0), numCols - 1);
            c_y = min(max(c_y, 0), numRows - 1);
            float filter_value = filter[f_y*filterWidth + f_x];
            color += filter_value*static_cast<float>(inputChannel[c_y*numCols + c_x]);
            
        }
    }
    
    outputChannel[m] = color;
  
}


__global__
void rgba_to_greyscale(const uchar4* const rgbaImage,
                       unsigned char* const greyImage,
                       int numRows, int numCols)
{

 int i = blockIdx.x * blockDim.x + threadIdx.x;// determina iteração das linhas
 int j = blockIdx.y * blockDim.y + threadIdx.y; //determina iteração das colunas
    if(i<numRows && j< numCols){
            uchar4 rgba = rgbaImage[i*numCols + j];
            float channelSum = .299f * rgba.x + .587f * rgba.y + .114f * rgba.z;
            greyImage[i*numCols +j]= channelSum;
        
    }
    
    
}
