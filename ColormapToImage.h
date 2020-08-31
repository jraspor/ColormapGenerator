#ifndef COLORMAP_TO_IMAGE_H
#define COLORMAP_TO_IMAGE_H

#include <iostream>
#include "src/ColorSpace.h"
#include "src/Comparison.h"
#include "src/Conversion.h"
#include "src/Utils.h"
#include <string>
#include <vector>

class ColormapToImage {
public:
    ColormapToImage(std::string fileName, int width, int height, std::vector<double> LVals, std::vector<double> aVals, std::vector<double> bVals);
    ~ColormapToImage();
};

#endif
