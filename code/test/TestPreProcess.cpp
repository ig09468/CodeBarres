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
    cout << "Ouverture de l'image OK" << endl;
    cv::imshow("Source Test", img);
}


/*
 * Affichage test de l'image après une modification en niveau de gris
 */
void TestPreProcess::testGreyscale() {
    cout << "Lancement Process : Greyscale" << endl;
    img = greyscale(img);
    cout << "GreyScale : OK" << endl;
    cv::imshow("Greyscale Test", img);
}

/*
 * Affichage test de la rotation d'une image
 */
void TestPreProcess::testRotate() {
    cout << "Lancement Process : Rotate" << endl;
    img = rotation(img,-90);
    cv::imshow("Rotate Test", img);
}

/*
 * Affichage test de l'image après un RollingBall
 */
void TestPreProcess::testRollingBall() {
    cout << "Lancement Process : RollingBall" << endl;
    //img = rollingBall(img);
    cv::imshow("RollingBall Test" ,img);

}


/*
 * Affichage test de l'image après une binarisation
 */
void TestPreProcess::testThreshold() {
    cout << "Lancement Process : Threshold" << endl;
    img = thresholdAuto(img);
    cout << "Threshold : OK" << endl;
    cv::imshow("Threshold Test",img);
}


/*
 * Affichage test de l'image après une redimension
 */
void TestPreProcess::testResize() {
    cout << "Lancement Process : Resize" << endl;
    img = resize(img, maxSize);
    cout << "Resize : OK" << endl;
    cv::imshow("Resize Test", img);
}

/*
 * Fonction de lancement des test
 */
void TestPreProcess::test(){
    cout << "Process TEST" << endl;
    testOpen();
    testResize();
    testGreyscale();
    testRotate();
    testThreshold();
    cv::waitKey(0);
}


