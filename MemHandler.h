#ifndef MEMHANDLER_H
#define MEMHANDLER_H 1

__global__
void copyImgToTS(const unsigned char* TS, const unsigned char* img,int cols, int rows);

__global__
void insertInBuffer(const unsigned char* BUFF, const unsigned char* img, int cols, int rows);

void allocApp(unsigned char* &TS, unsigned char* &BUFF, int cols, int rows, int sizeBUFF);
void deallocApp(unsigned char* &TS, unsigned char* &BUFF, int cols, int rows, int sizeBUFF);

#endif
