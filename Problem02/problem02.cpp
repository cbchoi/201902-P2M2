#include <iostream>
#include "tinygraybmp.h"

void moving_avg_func(unsigned char** dst, unsigned char** src, double* filter, int height, int width);

int main()
{
    tinygraybmp tb("test.bmp");

    int width = tb.get_width();
    int height = tb.get_height();

    unsigned char** image_buf = tb.get_image_buf();
    unsigned char** cloned_buf = tb.get_cloned_image_buf();

    double filter[3][3] = {{1/9.0,1/9.0,1/9.0},{1/9.0,1/9.0,1/9.0},{1/9.0,1/9.0,1/9.0}};

    //for(int k = 0; k < 10; k++)
    //    moving_avg_func(image_buf, cloned_buf, (double*)filter, height, width);

    tb.export_image("processed.bmp");
    return 0;
}

void moving_avg_func(unsigned char** dst, unsigned char** src, double* filter, int height, int width)
{
    for( int i = 1; i < height-1; i++)
    {
        for(int j = 1; j < width-1; j++)
        {
            dst[i][j] = dst[i-1][j+0] * filter[0+0] +
                        dst[i-1][j+1] * filter[0+1] +
                        dst[i-1][j+2] * filter[0+2] +
                        dst[i+0][j+0] * filter[1+0] +
                        dst[i+0][j+1] * filter[1+1] +
                        dst[i+0][j+2] * filter[1+2] +
                        dst[i+1][j+0] * filter[2+0] +
                        dst[i+1][j+1] * filter[2+1] +
                        dst[i+1][j+2] * filter[2+2];
        }
    }
}