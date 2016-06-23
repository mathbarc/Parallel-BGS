#ifndef BGS_H
#define BGS_H 1

typedef unsigned char uchar;

__global__
void BGS(uchar* buffer, int size, uchar* frame, int frame_size);

#endif
