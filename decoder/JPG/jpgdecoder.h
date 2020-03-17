/*
 * @Descripttion:
 * @Author: ljzone
 * @Date: 2020-03-09 22:18:52
 * @LastEditors: ljzone
 * @LastEditTime: 2020-03-12 23:27:46
 */

#ifndef JPGDECODER_H
#define JPGDECODER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "jpglib.h"
#include "jpeg.h"

FILE* read_jpeg_image_file(char* filename);

bool get_jpeg_image_data(FILE *fin);

void process_SOF(BYTE b, FILE *fin);

#endif   // jpgdecoder.h
