#include <iostream>
#include "PreProcess.h"


int main() {

    std::cout << "Bienvenue dans le projet Code-Barres Détection!" << std::endl;
    string src = "/home/meynadier/ProjectImg/img/ROTATE.jpg";

    cv::Mat img = openImg(src);
    cv::imshow("Avant", img);



    cv::Mat rezImg = resize(img, 512);
    cv::imshow("Après", rezImg);


    cv::Mat greyImg = greyscale(rezImg);
    cv::imshow("Greyscale", greyImg);
    cv::Mat binary = thresholdAuto(greyImg);
    cv::imshow("Binary", binary);

    cv::waitKey(0);
    return 0;
}