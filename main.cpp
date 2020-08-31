#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "ColormapToImage.h"
#include "Interpolation.h"

using namespace std;

//Interpolacija:
double interpolate(vector<double> &LData, vector<double> &bData, double x)
{
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

int main(int argc,char * argv[])
{
   //Divergentna color mapa
   //U sredini bijelo, divergira boja po b axis
   //Plava boja - u minusu, žuta boja - u plusu

   //Linearna color mapa
   //Promjenjivo po svjetlini - L

   vector<double> LData;
   vector<double> bData;

   //Definicija točaka
   //L za linearnu

   LData.push_back(0);
   LData.push_back(20);
   LData.push_back(40);
   LData.push_back(60);
   LData.push_back(100);

   //b za divergentnu

   bData.push_back(-60);
   bData.push_back(-40);
   bData.push_back(-20);
   bData.push_back(0);
   bData.push_back(20);

   const int numPoints = 100;
   vector<double> LVals, bVals;
   for (int i = 10; i <= numPoints; i++) LVals.push_back((double)i);

   // Interpoliranje
   for (double x : LVals)
   {
      double y = interpolate(LData, bData, x);
      bVals.push_back( y );
   }

   // Output
   #define SP << fixed << setw( 15 ) << setprecision( 6 ) <<
   #define NL << '\n'
   cout << "Originalno: \n";
   for (int i = 0; i < LData.size(); i++) cout SP bData[i] NL;
   cout << "\nInterpolirano: \n";
   for (int i = 0; i < LVals.size(); i++) cout SP bVals[i] NL;

   //LVals - interpolirana svjetlina
   //bVals - interpolirane vrijednosti plavo-žuto

   //Divergentna color mapa - interpolirani b vals

   vector<double> LValsDiv, aValsDiv;
   for(int i = 0; i < bVals.size(); i++) {
        LValsDiv.push_back(70);
        aValsDiv.push_back(0);
   }

    ColormapToImage divergentna("divergentnaMapa", 20, 200, LValsDiv, aValsDiv,  bVals);

    //Linearna color mapa - koristimo LVals - interpolirane vrijednosti za svijetlost

    vector<double> aValsLin, bValsLin;
    for(int i = 0; i < bVals.size(); i++) {
         aValsLin.push_back(-70);
         bValsLin.push_back(0);
    }

    ColormapToImage linearna("linearnaMapa", 20, 200, LVals, aValsLin,  bValsLin);
}
