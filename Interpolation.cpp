#include "Interpolation.h"
#include <vector>

Interpolation::Interpolation () {}
Interpolation::~Interpolation() {}

double Interpolation::interpolate(std::vector<double> &LData, std::vector<double> &bData, double x) {
    int size = LData.size();

    int i = 0;
    if (x >= LData[size - 2]){
       i = size - 2;
    } else{
       while (x > LData[i+1]) i++;
    }

    double xL = LData[i], yL = bData[i], xR = LData[i+1], yR = bData[i+1];

    if (x < xL) yR = yL;
    if (x > xR) yL = yR;


    double dydx = (yR - yL) / (xR - xL);

    return yL + dydx * (x - xL);
}
