#include <iostream>
#include "CImg.h"

using namespace cimg_library;

int main() {
    const char* filename = "input_image.jpg";
    CImg<unsigned char> image(filename);

    // Display original image
    CImgDisplay original_disp(image, "Original Image");

    // Apply a simple filter (invert colors)
    cimg_forXY(image, x, y) {
        for (int c = 0; c < image.spectrum(); ++c) {
            image(x, y, c) = 255 - image(x, y, c);
        }
    }

    // Display modified image
    CImgDisplay modified_disp(image, "Modified Image");

    // Wait for user to close windows
    while (!original_disp.is_closed() && !modified_disp.is_closed()) {
        original_disp.wait();
        modified_disp.wait();
    }

    return 0;
}
