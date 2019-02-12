//
// Created by meynadier on 12/02/19.
//

#include "TestPreProcess.h"


TestPreProcess::TestPreProcess(string &srcImg, int maxSize) : maxSize(maxSize){
    img=openImg(srcImg);

}

TestPreProcess::~TestPreProcess() = default;

/*
 * Affichage test de l'image d'origine
 */
void TestPreProcess::testOpen(){
    cv::imshow("Source Test", img);
}


/*
 * Affichage test de l'image après une modification en niveau de gris
 */
void TestPreProcess::testGreyscale() {
    img = greyscale(img);
    cv::imshow("Greyscale Test", img);
}

/*
 * Affichage test de l'image après une binarisation
 */
void TestPreProcess::testThreshold() {

    img = thresholdAuto(img);
    cv::imshow("Threshold Test",img);
}


/*
 * Affichage test de l'image après une redimension
 */
void TestPreProcess::testResize() {
    img = resize(img, maxSize);
    cv::imshow("Resize Test", img);
}

/*
 * Fonction de lancement des test
 */
void TestPreProcess::test(){
    testOpen();
    testResize();
    testGreyscale();
    testThreshold();
    cv::waitKey(0);
}