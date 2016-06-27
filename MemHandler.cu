#include "MemHandler.h"

__global__
void copyImgToGPU(const unsigned char* frameEntrada, const unsigned char* img, int cols, int rows);

__global__
void putInBuffer(const unsigned char* BUFF, const unsigned char* frameAtual, int cols, int rows, int sizeBUFF, int pos);

void alloc(unsigned char* &frameEntrada, unsigned char* &frameIntermediario, unsigned char* &frameTratado, unsigned char* &fore, unsigned char* &BUFF, int cols, int rows, int sizeBUFF);
void dealloc(unsigned char* &frameEntrada, unsigned char* &frameIntermediario, unsigned char* &frameTratado, unsigned char* &fore, unsigned char* &BUFF, int cols, int rows, int sizeBUFF);

