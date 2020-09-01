#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <iostream>
#include <vector>

class Interpolation {
public:
    Interpolation();
    ~Interpolation();
    double interpolate(std::vector<double> &LData, std::vector<double> &bData, double x);
};

#endif
