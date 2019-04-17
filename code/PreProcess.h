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
cv::Mat hough(const cv::Mat& sourceImg, const int thresh);
cv::Mat convexHull(const cv::Mat& sourceImg);
cv::Mat gradient(const cv::Mat& sourceImg);
cv::Mat binaryBlur(const cv::Mat& gray);
cv::Mat closeTraitement(const cv::Mat &binary_blur, int imgRows, int imgCols);
cv::Mat detectContours(const cv::Mat &close);
cv::Mat fusionImg(const cv::Mat &sourceImg, const cv::Mat &drawing);

bool modePaysage(const cv::Mat& sourceImg);
int determinateThreshold(const cv::Mat& sourceImg);
cv::Mat calculHistogram(const cv::Mat& sourceImg);

cv::Mat rectifValue(cv::Mat sourceImg);

#endif //CODEBARRES_PREPROCESS_H
