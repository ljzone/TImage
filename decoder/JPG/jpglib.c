/*
 * @Descripttion:
 * @Author: ljzone
 * @Date: 2020-03-12 23:55:58
 * @LastEditors: ljzone
 * @LastEditTime: 2020-03-13 00:03:43
 */

#include "jpglib.h"

void process_SOI()
{
    printf("SOI\n");
}

void process_APP(BYTE b)
{
    printf("APP: \n%X \n", b.value);
}

void process_DQT()
{
    printf("DQT\n");
}

void process_DRI()
{
    printf("DRI\n");
}

void process_DHT()
{
    printf("DHT\n");
}

void process_SOF(BYTE b, FILE *fin)
{
	switch(b.value)
	{
		case JPEG_SOF0: read_SOF0(fin); break;
	}
}

void process_SOS()
{
    printf("SOS\n");
}

void process_EOI()
{
    printf("EOI\n");
}


void read_SOF0(FILE *fin)
{
	printf("SOF0\n");
	WORD wd;
	BYTE b;

	read_word(&wd, fin);
	printf("%d ", ((wd.W.h<<8) + wd.W.l));

	read_byte(&b, fin);
	printf("%d ", b.value);

	read_word(&wd, fin);
	printf("%d ", ((wd.W.h<<8) + wd.W.l));

	read_word(&wd, fin);
	printf("%d ", ((wd.W.h<<8) + wd.W.l));

	read_byte(&b, fin);
	printf("%d ", b.value);


	printf("\n");
}


