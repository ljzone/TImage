/*
 * @Descripttion:
 * @Author: ljzone
 * @Date: 2020-03-09 22:56:15
 * @LastEditors: ljzone
 * @LastEditTime: 2020-03-13 00:21:33
 */

#include "jpglib.h"
#include "jpgdecoder.h"
#include <stdio.h>
#include <stdlib.h>

void read_image(char* filename)
{
	WORD wd;
	BYTE b;

	FILE *fin = fopen(filename, "rb");
	if(fin == NULL)
	{
		fprintf(stderr, "Can not open %s\n", filename);
		exit(1);
	}

	int n;

	while((n=read_byte(&b, fin)) > 0)
	{
		if(b.value == 0xff)
		{
			read_byte(&b, fin);
			switch(b.value)
			{
				case JPEG_SOI : process_SOI(); break;
				case JPEG_APP0: process_APP0(); break;
				case JPEG_DQT : process_DQT(); break;
				case JPEG_DRI : process_DRI(); break;
				case JPEG_DHT : process_DHT(); break;
				case JPEG_SOF0 : process_SOF(); break;
				case JPEG_SOS : process_SOS(); break;
				case JPEG_EOI : process_EOI(); break;
			}
		}
	}

}
