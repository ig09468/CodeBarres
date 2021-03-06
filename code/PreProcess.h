//
// Created by meynadier on 07/02/19.
//

#ifndef CODEBARRES_PREPROCESS_H
#define CODEBARRES_PREPROCESS_H

#include <opencv2/core/mat.hpp>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace std;

cv::Mat openImg(string src);

cv::Mat greyscale(const cv::Mat& sourceImg);
cv::Mat thresholdAuto(const cv::Mat& sourceImg);

cv::Mat rotation(const cv::Mat& sourceImg, int angle);
cv::Mat resize(const cv::Mat& sourceImg, const int& maxSize);
cv::Mat rollingBall(const cv::Mat& sourceImg, const int& radius);
cv::Mat getBackground(const cv::Mat& sourceImg, const int& radius);
cv::Mat convexHull(const cv::Mat& sourceImg);
cv::Mat gradient(const cv::Mat& sourceImg);
cv::Mat binaryBlur(const cv::Mat& gray,const int seuil);
cv::Mat closeTraitement(const cv::Mat &binary_blur);
vector<vector<cv::Point>> detectContours(const cv::Mat &close);
vector<cv::Vec4i> hough(const cv::Mat& sourceImg, const int thresh);
cv::Mat fusionImg(const cv::Mat &sourceImg, const cv::Mat &drawing);



void preprocess(string src, string save, int dim);


bool modePaysage(const cv::Mat& sourceImg);
int determinateThreshold(const cv::Mat& sourceImg);
cv::Mat calculHistogram(const cv::Mat& sourceImg);
vector<cv::Point> extremPoint(vector<cv::Point>);


cv::Mat rectifValue(cv::Mat sourceImg);

#endif //CODEBARRES_PREPROCESS_H
