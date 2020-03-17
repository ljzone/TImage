#include "jpeg.h"

bool read_jpeg(char *filename, JPEG *jpg)
{
	fin = read_jpeg_image_file(filename);
	if(fin == NULL)
	{
		return false;
	}

	get_jpeg_image_data(fin);



	jpg->heigh = jpeg.heigh;
	jpg->width = jpeg.width;


	if(fin != NULL)
	{
		fclose(fin);
	}
	return true;
}
