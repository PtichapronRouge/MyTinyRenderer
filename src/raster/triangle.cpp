/**@file	/data/Projets/MyTinyRenderer/src/raster/triangle.cpp
 * @author	talos
 * @version	802
 * @date
 * 	Created:	12th Apr 2020
 * 	Last Update:	12th Apr 2020
 */

#include "triangle.hpp"
#include "line.hpp"

#include <cassert>

bool is_inside(Vec2i pt, Vec2i v0, Vec2i dv1, Vec2i dv2)
{
    auto dpt = v0-pt;
    auto bary = Vec3i(dv1.x, dv2.x, dpt.x)^Vec3i(dv1.y, dv2.y, dpt.y);

    if (bary.z > 0)
        return bary.x >= 0 && bary.y >= 0 && (bary.z - bary.x - bary.y) >= 0;
    return bary.x <= 0 && bary.y <= 0 && (bary.z - bary.x - bary.y) <= 0;
}

void empty_triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage& img, const TGAColor& color)
{
    plot_line(v0, v1, img, color);
    plot_line(v1, v2, img, color);
    plot_line(v2, v0, img, color);
}

void fill_triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage& img, const TGAColor& color)
{
    // check if triangle is degenerate
    auto dv1 = v1-v0;
    auto dv2 = v2-v0;
    if ((Vec3i(dv1.x, dv1.y, 0)^Vec3i(dv2.x, dv2.y, 0)).z == 0) {
        empty_triangle(v0, v1, v2, img, color);
        return;
    }

    // bounding box
    int xm = std::min(std::min(v0.x, v1.x), v2.x);
    int xM = std::max(std::max(v0.x, v1.x), v2.x);
    int ym = std::min(std::min(v0.y, v1.y), v2.y);
    int yM = std::max(std::max(v0.y, v1.y), v2.y);

    for (int x = xm; x <= xM; ++x) {
        for (int y = ym; y <= yM; ++y) {
            if (is_inside(Vec2i(x,y), v0, dv1, dv2)) {
                img.set(x,y,color);
            }
        }
    }
}
