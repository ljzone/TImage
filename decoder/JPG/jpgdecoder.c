/*
 * @Descripttion:
 * @Author: ljzone
 * @Date: 2020-03-09 22:56:15
 * @LastEditors: ljzone
 * @LastEditTime: 2020-03-13 10:15:23
 */
#include "jpgdecoder.h"

FILE* read_jpeg_image_file(char* filename)
{
	/*
	 * 获取文件指针
	 * 
	 */

	FILE *fin = fopen(filename, "rb");
	if(fin == NULL)
	{
		fprintf(stderr, "Can not open %s\n", filename);
		fin = NULL;
		return NULL;
	}

	int n;
	if((n=read_word(&wd, fin)) > 0  \
			&&  wd.W.h == 0xff  \
			&& wd.W.l == JPEG_SOI)
	{
		return fin;
	}

	fprintf(stderr, "NOT jpg/jpeg format");
	return NULL;
}



bool get_jpeg_image_data(FILE *fin)
{

	// 解析各类jpeg标记

	if(fin == NULL)
	{
		fprintf(stderr, "fin = NULL");
		return false;
	}

	int n;
	while((n=read_byte(&b, fin)) > 0)
	{
		if(b.value == 0xff)
		{
			read_byte(&b, fin);
			switch(b.value)
			{
				case JPEG_SOF0: process_SOF(b, fin); break;
			}
		}
	}

}


void process_SOF(BYTE b, FILE *fin)
{
	read_word(&wd, fin);
	read_byte(&wd, fin);

	read_word(&wd, fin);
	jpeg.width = (wd.W.h << 8) + wd.W.l;
	read_word(&wd, fin);
	jpeg.heigh = (wd.W.h << 8) + wd.W.l;

}
