#include "ColormapToImage.h"

ColormapToImage::ColormapToImage(std::string fileName, int width, int height, std::vector<double> LVals, std::vector<double> aVals, std::vector<double> bVals) {
    FILE *imageFile;
    ColorSpace::Rgb rgb;

    imageFile=fopen((fileName + ".ppm").c_str(),"wb");
    if(imageFile==NULL){
       perror("ERROR: Cannot open output file");
       exit(EXIT_FAILURE);
    }

//    std::cout << width << "\n" << height << "\n" << LVals.size();

    fprintf(imageFile,"P3 ");
    fprintf(imageFile,"%d %d ", int(LVals.size()*width), height);
    fprintf(imageFile,"255\n");

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < LVals.size(); j++){

           ColorSpace::Lab lab(LVals[j], aVals[j], bVals[j]);
           lab.ToRgb(&rgb);

           int r = abs(rgb.r);
           int g = abs(rgb.g);
           int b = abs(rgb.b);

           for(int k = 0; k < width; k++) {
               fprintf(imageFile, "%d %d %d ", r, g, b);
           }
         }
        fprintf(imageFile, "\n");
    }

    fclose(imageFile);
}

ColormapToImage:: ~ColormapToImage() {}
