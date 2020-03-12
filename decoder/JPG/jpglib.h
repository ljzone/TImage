/*
 * @Descripttion:
 * @Author: ljzone
 * @Date: 2020-03-12 22:42:37
 * @LastEditors: ljzone
 * @LastEditTime: 2020-03-13 00:02:30
 */

#include <stdio.h>
#include <stdlib.h>


#ifndef JPGLIB_H
#define JPGLIB_H


#define JPEG_SOI 0xD8
#define JPEG_EOI 0xD9

#define JPEG_APP0 0xE0
#define JPEG_DQT  0xDB
#define JPEG_DRI  0xDD
#define JPEG_DHT  0xC4

#define JPEG_SOF0  0xC0
#define JPEG_SOF1  0xC1
#define JPEG_SOF2  0xC2
#define JPEG_SOF3  0xC3
#define JPEG_SOF5  0xC5
#define JPEG_SOF6  0xC6
#define JPEG_SOF7  0xC7
#define JPEG_SOF8  0xC8
#define JPEG_SOF9  0xC9
#define JPEG_SOFA  0xCA
#define JPEG_SOFB  0xCB
#define JPEG_SOFC  0xCC
#define JPEG_SOFD  0xCD
#define JPEG_SOFE  0xCE
#define JPEG_SOFF  0xCF

#define JPEG_SOS  0xDA

#define BYTESIZE 1
#define WORDSIZE 2

typedef struct
{
	unsigned int value: 8;
}Byte;


typedef struct
{
	unsigned int h: 8;
	unsigned int l: 8;
}Word;

typedef union
{
	unsigned int value: 16;
	Word W;
}WORD;

typedef Byte BYTE;


#define read_byte(wd,file) fread(wd, BYTESIZE, 1, (file))
#define read_word(wd,file) fread(wd, WORDSIZE, 1, (file))



void process_SOI();
void process_EOI();

void process_APP0();
void process_DQT();
void process_DRI();
void process_DHT();
void process_SOF();
void process_SOS();

#endif // jpglib.h