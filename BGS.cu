#include "BGS.h"
__global__
void BGS(uchar* buffer, int buffer_size, uchar* frame, int frame_size){
	const int x =  blockIdx.x * blockDim.x + threadIdx.x;
    const int y =  blockIdx.y * blockDim.y + threadIdx.y;
    int avg = 0;
    int sum = 0;
    if(x < frame_size && y < frame_size){
    	for(int i = 0; i < buffer_size; i++){
    		//calcula a soma dos pixels
     	}
     	avg = sum / buffer_size;
     	//calcula a diferença e escreve no frame do vetor resposta
    }
}
