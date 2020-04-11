#include "tgaimage.h"

const TGAColor white = TGAColor(255,255,255,0);
const TGAColor red   = TGAColor(255,0,0,0);
const TGAColor blue  = TGAColor(0,0,255,0);

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

