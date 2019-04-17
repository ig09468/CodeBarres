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
    //cv::imshow("Source Test", img);
}


/*
 * Affichage test de l'image après une modification en niveau de gris
 */
void TestPreProcess::testGreyscale() {
    cout << "Lancement Process : Greyscale" << endl;
    cv::Mat img = greyscale(this->img);
    cout << "GreyScale : OK" << endl;
    //cv::imshow("Greyscale Test", img);
}

/*
 * Affichage test de la rotation d'une image
 */
void TestPreProcess::testRotate() {
    cout << "Lancement Process : Rotate" << endl;
    cv::Mat img = rotation(this->img,-90);
    cv::imshow("Rotate Test", img);
}

/*
 * Affichage test de l'image après un RollingBall
 */
void TestPreProcess::testRollingBall(){
	cout << "Lancement Process : Rolling Ball" << endl;
    cv::Mat img = rollingBall(this->img, 25);
    cout << "Rolling Ball : OK" << endl;
    cv::imshow("Rolling Ball",img);
}


/*
 * Affichage test de l'image après une binarisation
 */
void TestPreProcess::testThreshold() {
    cout << "Lancement Process : Threshold" << endl;
    cv::Mat img = thresholdAuto(this->img);
    cout << "Threshold : OK" << endl;
    cv::imshow("Threshold Test",img);
}


/*
 * Affichage test de l'image après une redimension
 */
void TestPreProcess::testResize() {
    cout << "Lancement Process : Resize" << endl;
    cv::Mat img = resize(this->img, maxSize);
    cout << "Resize : OK" << endl;
    cv::imshow("Resize Test", img);
}



void TestPreProcess::testHough(){
    cout << "Lancement Process : Hough" << endl;
    cv::Mat img = hough(this->img,50);
    cout << "Hough : OK" << endl;
    cv::imshow("Hough", img);
}

void TestPreProcess::testGradient () {
    cout << "Lancement Process : Gradient" << endl;
    cv::Mat img = gradient(this->img);
    cv::imshow("Gradient", img);
    cout << "Gradient : OK" << endl;
}

void TestPreProcess::testBinaryBlur () {
    cout << "Lancement Process : Binary_Blur" << endl;
    cv::Mat img = binaryBlur(this->img);
    cv::imshow("Gradient", img);
    cout << "Binary_Blur : OK" << endl;
}

void TestPreProcess::testDetectContours () {
    cout << "Lancement Process : Contours" << endl;
    cv::Mat imgDrawing = detectContours(img);
    cv::imshow("Detect Contours", imgDrawing);
    cv::Mat img = fusionImg(this->img, imgDrawing);
    cv::imshow("Contours + Origine", img);
    cout << "Contours : OK" << endl;
}



void TestPreProcess::testCloseTraitement () {
    cout << "Lancement Process : Close" << endl;
    cv::Mat img = closeTraitement(this->img);
    cv::imshow("Gradient", img);
    cout << "Close : OK" << endl;
}



/*
 * Fonction de lancement des test
 */
void TestPreProcess::test(){
    cout << "Process TEST" << endl;
    testOpen();
    testGreyscale();

    testResize();
    testRollingBall();
    //testThreshold();
    testHough();
    //testRotate();
    cv::waitKey(0);




}
