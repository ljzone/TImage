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
#define JPEG_APP1 0xE1
#define JPEG_APP2 0xE2
#define JPEG_APP3 0xE3
#define JPEG_APP4 0xE4
#define JPEG_APP5 0xE5
#define JPEG_APP6 0xE6
#define JPEG_APP7 0xE7
#define JPEG_APP8 0xE8
#define JPEG_APP9 0xE9
#define JPEG_APPA 0xEA
#define JPEG_APPB 0xEB
#define JPEG_APPC 0xEC
#define JPEG_APPD 0xED
#define JPEG_APPE 0xEE
#define JPEG_APPF 0xEF

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

void process_APP(BYTE b);
void process_DQT();
void process_DRI();
void process_DHT();
void process_SOF(BYTE b, FILE *fin);
void process_SOS();

void read_SOF0(FILE *fin);
#endif // jpglib.h
