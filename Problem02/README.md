# Problem02 2D Moving Average Function (40 points)

In this problem you should fill in the blanks to make blurred image. 
This is very simple problem. You can get blurred image by applying matrix multiplication. 
For example, if you want to calculate (i, j) data, you should use 9 data, (i-1, j-1), (i-1, j), (i-1, j+1), (i, j-1), (i, j), (i, j+1), (i+1, j-1), (i+1, j), and (i+1, j+1), to calculate the (i, j)
The formula is given as follow:
`
dst's (i, j) = 1/9 * src's (i-1, j-1) + 1/9 * src's (i-1, j) + 1/9 * src's (i-1, j+1) + 1/9 * src's (i, j-1) + 1/9 * src's (i, j) + 1/9 * src's (i, j+1) + 1/9 * src's (i+1, j-1) + 1/9 * src's (i+1, j) + 1/9 * src's (i+1, j+1) 
`

Hint) You should use nested for statements.
Hint) Refer the support material.
```C++
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

    moving_avg_func(image_buf, cloned_buf, (double*)filter, height, width);

    tb.export_image("processed.bmp");
    return 0;
}

void moving_avg_func(unsigned char** dst, unsigned char** src, double* filter, int height, int width)
{















}

```
You should complete the logic to work properly. 
You may refer the output result of the program using output program.
You may execute the program as follows.
```
YourProjectDirectory/Problem02 $./output
```
