#include "tgaimage.h"
#include "line.hpp"
#include "triangle.hpp"
#include "objmodel.hpp"

const TGAColor white = TGAColor(255,255,255,0);
const TGAColor red   = TGAColor(255,0,0,0);
const TGAColor blue  = TGAColor(0,0,255,0);
const TGAColor green = TGAColor(0,255,0,0);

int main(int argc, char* argv[])
{
    TGAImage image(200,200, TGAImage::RGB);

    Vec2i t0[3] = {Vec2i(10, 70),   Vec2i(50, 160),  Vec2i(70, 80)};
    Vec2i t1[3] = {Vec2i(180, 50),  Vec2i(150, 1),   Vec2i(70, 180)};
    Vec2i t2[3] = {Vec2i(180, 150), Vec2i(120, 160), Vec2i(130, 180)};
    //empty_triangle(t0[0], t0[1], t0[2], image, white);
    //empty_triangle(t1[0], t1[1], t1[2], image, white);
    //empty_triangle(t2[0], t2[1], t2[2], image, white);
    fill_triangle(t0[0], t0[1], t0[2], image, blue);
    fill_triangle(t1[0], t1[1], t1[2], image, red);
    fill_triangle(t2[0], t2[1], t2[2], image, green);

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}

