#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include <vector>

class Fractal
{
    // Construction
    public:
        virtual ~Fractal() {};

    // Methods
    public:
        virtual void draw(
            unsigned char *img,
            unsigned w, unsigned h,
            double x1, double y1,
            double x2, double y2
        ) const = 0;
};

#endif // FRACTAL_HPP
