#include "MemHandler.h"

__global__
void copyImgToGPU(const unsigned char* frameEntrada, const unsigned char* img, int cols, int rows);

__global__
void putInBuffer(const unsigned char* BUFF, int cols, int rows, int sizeBUFF, int pos);

void alloc(unsigned char* &frameEntrada,unsigned char* &frameTratado, unsigned char* &BUFF, int cols, int rows, int sizeBUFF);
void dealloc(unsigned char* &frameEntrada, unsigned char* &frameTratado, unsigned char* &BUFF, int cols, int rows, int sizeBUFF);

