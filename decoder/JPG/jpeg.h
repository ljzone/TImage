#ifndef JPEG_H
#define JPEG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "jpgdecoder.h"


typedef struct
{
	int width;  // 图片宽度
	int heigh;  // 图片高度

	int channels; // 图片通道

}JPEG;

FILE *fin;
JPEG jpeg;

bool read_jpeg(char* filename, JPEG *jpg);

#endif  // jpeg.h
