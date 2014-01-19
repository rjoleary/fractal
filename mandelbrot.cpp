#include "mandelbrot.hpp"

#include <climits>
#include <complex>

void Mandelbrot::draw(
        unsigned char *img,
        unsigned w, unsigned h,
        double x1, double y1,
        double x2, double y2
    ) const
{
    const int maxIteration = CHAR_MAX;

    for (unsigned row = 0; row < h; row++)
    {
        for (unsigned col = 0; col < w; col++)
        {
            std::complex<double> c(
                x1 + col * (x2 - x1) / w,
                y1 + row * (y2 - y1) / h
            );
            std::complex<double> z;
            int iteration = 0;

            while (z.imag() * z.imag() + z.real() * z.real() < 4 &&
                   iteration < maxIteration)
            {
                z = z * z + c;
                iteration++;
            }

            img[row*w+col] = CHAR_MAX - iteration;
        }
    }
}
