/**@file	/data/Projets/MyTinyRenderer/src/raster/line.hpp
 * @author	talos
 * @version	802
 * @date
 * 	Created:	11th Apr 2020
 * 	Last Update:	11th Apr 2020
 */

#ifndef LINE_HPP
#define LINE_HPP

#include "tgaimage.h"
#include "vector.hpp"

void plot_line_low(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color);
void plot_line_high(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color);
void plot_line(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor& color);

void plot_line(Vec2i v0, Vec2i v1, TGAImage& image, const TGAColor& color);

#endif // LINE_HPP
