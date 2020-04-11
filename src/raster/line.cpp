/**@file	/data/Projets/MyTinyRenderer/src/raster/line.cpp
 * @author	talos
 * @version	802
 * @date
 * 	Created:	11th Apr 2020
 * 	Last Update:	11th Apr 2020
 */

#include "line.hpp"

#include <math.h>

void plot_line_low(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color)
{
    int dx = 2*(x1-x0);
    int dy = 2*(y1-y0);

    int delta_y = 1;
    if (dy < 0) {
        delta_y = -1;
        dy = -dy;
    }
    int offset = dy - dx/2;

    for (; x0 <= x1; ++x0) {
        image.set(x0,y0,color);
        if (offset >= 0) {
            y0 += delta_y;
            offset -= dx;
        }
        offset += dy;
    }
}

void plot_line_high(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color)
{
    int dx = 2*(x1-x0);
    int dy = 2*(y1-y0);

    int delta_x = 1;
    if (dx < 0) {
        delta_x = -1;
        dx = -dx;
    }
    int offset = dx - dy/2;

    for (; y0 <= y1; ++y0) {
        image.set(x0, y0, color);
        if (offset >= 0) {
            x0 += delta_x;
            offset -= dy;
        }
        offset += dx;
    }
}

void plot_line(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color)
{
    // gradient > 1
    if (abs(y1-y0) >= abs(x1-x0)) {
        if (y0 < y1) {
            plot_line_high(x0, y0, x1, y1, image, color);
        }
        else {
            plot_line_high(x1, y1, x0, y0, image, color);
        }
    }
    // gradient <= 1
    else {
        if (x0 < x1) {
            plot_line_low(x0, y0, x1, y1, image, color);
        }
        else {
            plot_line_low(x1, y1, x0, y0, image, color);
        }
    }
}
