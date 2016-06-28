#include "Filtros.h"
#include "MemHandler.h"
#include "BGS.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main(int argc, char** argv){

	if(argc<3){
		std::cout<<"Uso: BGS caminho_para_video tamanho_buffer"<<std::endl;
		return -1;
	}

	cv::VideoCapture in(argv[1]);

	if(!in.isOpened()){
		std::cout<<argv[1]<<" não pode ser aberto"<<std::endl;
		return -2;
	}

	int buff_size = atoi(argv[2]);

	int cols = (int)in.get(CV_CAP_PROP_FRAME_WIDTH);
	int rows = (int)in.get(CV_CAP_PROP_FRAME_HEIGHT);

	unsigned char* d_framein;
	unsigned char* d_framet;
	unsigned char* d_frameint;
	unsigned char* d_fore;
	unsigned char* d_buffer;
	int pos = 0;
	alloc(d_framein, d_framet, d_frameint, d_fore, d_buffer, cols, rows, buff_size);



	cv::Mat frame;
	in >> frame;
	while(!frame.empty()){
		copyImgToGPU(d_framein,frame.ptr<unsigned char>(),cols,rows);
		rgb_to_greyscale(d_framein, d_framet, rows, cols);
		gaussian_blur(d_framet, , rows, cols, const float* const filter, const int filterWidth);

		BGS(d_buffer, buff_size, d_framet, cols*rows, d_fore);
		putInBuffer(d_buffer, d_framet, cols, rows, buff_size, pos);
		pos++;
		if (pos > buff_size)
			pos = 0;
	}
	

	in.release();
	frame.release();
	dealloc(d_framein, d_framet, d_frameint, d_fore, d_buffer, cols, rows, buff_size);

	return 0;
}
