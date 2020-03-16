/*
 * @Descripttion:
 * @Author: ljzone
 * @Date: 2020-03-09 22:56:15
 * @LastEditors: ljzone
 * @LastEditTime: 2020-03-13 10:15:23
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
								
				case JPEG_APP0:
				case JPEG_APP1:
				case JPEG_APP2:
				case JPEG_APP3:
				case JPEG_APP4:
				case JPEG_APP5:
				case JPEG_APP6:
				case JPEG_APP7:
				case JPEG_APP8:
				case JPEG_APP9:
				case JPEG_APPA:
				case JPEG_APPB:
				case JPEG_APPC:
				case JPEG_APPD:
				case JPEG_APPE:
				case JPEG_APPF: process_APP(b); break;

				case JPEG_DQT : process_DQT(); break;
				case JPEG_DRI : process_DRI(); break;
				case JPEG_DHT : process_DHT(); break;
				case JPEG_SOF0 : 
				case JPEG_SOF1 : 
				case JPEG_SOF2 : 
				case JPEG_SOF3 : 
				case JPEG_SOF5 : 
				case JPEG_SOF6 : 
				case JPEG_SOF7 : 
				case JPEG_SOF8 : 
				case JPEG_SOF9 : 
				case JPEG_SOFA : 
				case JPEG_SOFB : 
				case JPEG_SOFC : 
				case JPEG_SOFD : 
				case JPEG_SOFE : 
				case JPEG_SOFF : process_SOF(b, fin); break;
				case JPEG_SOS : process_SOS(); break;
				case JPEG_EOI : process_EOI(); break;
			}
		}
	}


	fclose(fin);

}
