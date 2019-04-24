//
// Created by meynadier on 12/02/19.
//

#include "TestPreProcess.h"


TestPreProcess::TestPreProcess(string &srcImg, int maxSize) : maxSize(maxSize){
    img=openImg(srcImg);
    img.copyTo(img_copy);
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
    this->img_copy = greyscale(this->img_copy);
    cv::imshow("Greyscale Test", this->img_copy);
    cout << "GreyScale : OK" << endl;
}

/*
 * Affichage test de la rotation d'une image
 */
void TestPreProcess::testRotate() {
    cout << "Lancement Process : Rotate" << endl;
    this->img_copy = rotation(this->img_copy,-90);
    cv::imshow("Rotate Test", this->img_copy);
}

/*
 * Affichage test de l'image après un RollingBall
 */
void TestPreProcess::testRollingBall(){
	cout << "Lancement Process : Rolling Ball" << endl;
    this->img_copy = rollingBall(this->img_copy, 25);
    cout << "Rolling Ball : OK" << endl;
    cv::imshow("Rolling Ball",this->img_copy);
}


/*
 * Affichage test de l'image après une binarisation
 */
void TestPreProcess::testThreshold() {
    cout << "Lancement Process : Threshold" << endl;
    this->img_copy = thresholdAuto(this->img_copy);
    cout << "Threshold : OK" << endl;
    cv::imshow("Threshold Test",this->img_copy);
}


/*
 * Affichage test de l'image après une redimension
 */
void TestPreProcess::testResize() {
    cout << "Lancement Process : Resize" << endl;
    this->img = resize(this->img, maxSize);
    this->img_copy = resize(this->img_copy, maxSize);
    cout << "Resize : OK" << endl;
    cv::imshow("Resize Test", this->img_copy);
}



void TestPreProcess::testHough(){
    cout << "Lancement Process : Hough" << endl;
//    this->img_copy = hough(this->img_copy,50);
    cout << "Hough : OK" << endl;
    cv::imshow("Hough", img);
}

void TestPreProcess::testGradient () {
    cout << "Lancement Process : Gradient" << endl;
    this->img_copy = gradient(this->img_copy);
    cv::imshow("Gradient", img_copy);
    cout << "Gradient : OK" << endl;
}

void TestPreProcess::testBinaryBlur () {
    cout << "Lancement Process : Binary_Blur" << endl;
    this->img_copy = binaryBlur(this->img_copy,100);
    cv::imshow("Binary_Blur", this->img_copy);
    cout << "Binary_Blur : OK" << endl;
}

void TestPreProcess::testDetectContours () {
    cout << "Lancement Process : Contours" << endl;
    vector<vector<cv::Point>> contours = detectContours(this->img_copy);
    cv::Mat drawing = cv::Mat::zeros(img_copy.size(),CV_8UC3);
    for(size_t i = 0 ; i < contours.size(); i++){
        cv::Scalar color = cv::Scalar(0,0,255);
        cv::drawContours(drawing,contours,i,color,2,cv::LINE_8);
    }
    cv::imshow("Detect Contours", drawing);
    this->img_copy = fusionImg(this->img, drawing);
    cv::imshow("Contours + Origine", this->img_copy);
    cout << "Contours : OK" << endl;
}



void TestPreProcess::testCloseTraitement () {
    cout << "Lancement Process : Close" << endl;
    this->img_copy = closeTraitement(this->img_copy);
    cv::imshow("Close", this->img_copy);
    cout << "Close : OK" << endl;
}



/*
 * Fonction de lancement des test
 */
void TestPreProcess::test(){
    cout << "Process TEST" << endl;
    testOpen();
    testResize();
    testGreyscale();
    testGradient();
    testBinaryBlur();
    testCloseTraitement();
    testDetectContours();
    //testRollingBall();
    //testThreshold();
    //testHough();
    //testRotate();
    cv::waitKey(0);




}
