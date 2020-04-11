#include "tgaimage.h"
#include "line.hpp"

const TGAColor white = TGAColor(255,255,255,0);
const TGAColor red   = TGAColor(255,0,0,0);
const TGAColor blue  = TGAColor(0,0,255,0);


int main(int argc, char* argv[])
{
    int x0 = 0,
        y0 = 0,
        x1 = 100,
        y1 = 100;
    if(argc == 5) {
        x0 = std::stoi(argv[1]),
        y0 = std::stoi(argv[2]),
        x1 = std::stoi(argv[3]),
        y1 = std::stoi(argv[4]);
    }

    TGAImage image(100,100, TGAImage::RGB);
    plot_line(x0,y0, x1,y1, image,red);
    plot_line(x1,y1, x0,y0, image,blue);
    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}

