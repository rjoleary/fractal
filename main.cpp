#include <iostream>
#include <algorithm>
#include <cmath>

#include "mandelbrot.hpp"

#include "CImg.h"
namespace cimg = cimg_library;

int main()
{
    // Create a window with the size 500*500.
    cimg::CImg<unsigned char> image(500, 500, 1, 1);
    cimg::CImgDisplay display(image, "Fractal", 1);

    // The camera is defined by its center (x,y) and a zoom level.
    double zoom = 0.5, x = -.5, y = 0;

    while (!display.is_closed())
    {
        auto width = display.window_width();
        auto height = display.window_height();
        double ratio = double(width) / height;

        if (display.is_resized())
        {
            image.resize(width, height, -1);
            display.resize(width, height, true);
        }

        // logic for zooming
        if (display.wheel())
        {
            double oldZoom = zoom;
            zoom = std::max(0.5, zoom * std::pow(2.0, display.wheel()));

            if (display.mouse_x() != -1)
            {
                double mx = ratio * (2.0 * display.mouse_x() / width - 1);
                double my = ratio * (2.0 * display.mouse_y() / height - 1);

                x += mx / oldZoom - mx / zoom;
                y += my / oldZoom - my / zoom;
            }

            display.set_wheel();
        }

        // logic for centering
        if (display.button() == 1)
        {
            x = x + ratio * (2.0 * display.mouse_x() / width - 1) / zoom;
            y = y + ratio * (2.0 * display.mouse_y() / height - 1) / zoom;
        }

        // coordinates of a rectangle defining the camera
        double x1 = x - ratio / zoom;
        double y1 = y - 1 / zoom;
        double x2 = x + ratio / zoom;
        double y2 = y + 1 / zoom;

        Mandelbrot().draw(image.data(), width, height, x1, y1, x2, y2);
        display.render(image);
        display.paint();
        display.wait();
    }
}
