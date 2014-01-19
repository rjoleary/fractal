#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include "fractal.hpp"

#include <vector>

class Mandelbrot : public Fractal
{
    // Methods
    public:
        virtual void draw(
            unsigned char *img,
            unsigned w, unsigned h,
            double x1, double y1,
            double x2, double y2
        ) const;
};

#endif // MANDELBROT_HPP__INCLUDED
