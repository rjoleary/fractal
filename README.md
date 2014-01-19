Fractal
=======

This is a short program that renders an interactive Mandelbrot Set. There will
be other types of fractals coming soon if I have time. I am also planning to
add a few optimizations because, as it stands, the interactivity is quite slow.


Controls
--------

Use the scroll wheel to zoom in and out. Click anywhere to centre the camera.


Building
--------

Building the source is pretty easy. It has been tested under Ubuntu and
Windows.

In linux, run `make` in source directory. Beforehand, you may need to install
the `cimg-dev` and `xorg-dev` packages. Under Ubuntu, I use:

    sudo apt-get install cimg-dev xorg-dev

In Windows, download the CImg header file into you include directory. It can be
obtained from the [CImg website](http://cimg.sourceforge.net/). Copy all the
source files (cpp/hpp) into a Visual C++ solution and compile. Some C++11
features are required, so that means Visual C++ 2010 or above.


License
-------

The license is found in the `LICENSE.txt` file.
