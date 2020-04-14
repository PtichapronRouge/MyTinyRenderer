/**@file	/data/Projets/MyTinyRenderer/src/raster/triangle.hpp
 * @author	talos
 * @version	802
 * @date
 * 	Created:	12th Apr 2020
 * 	Last Update:	12th Apr 2020
 */

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "tgaimage.h"
#include "vector.hpp"

void empty_triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage& img, const TGAColor& color);

void fill_triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage& img, const TGAColor& color);


#endif // TRIANGLE_HPP
