//
// Created by meynadier on 07/02/19.
//

#ifndef CODEBARRES_PREPROCESS_H
#define CODEBARRES_PREPROCESS_H

#include <core/mat.hpp>
#include "opencv.hpp"
#include <iostream>
#include <string>

using namespace std;

cv::Mat openImg(string src);

cv::Mat greyscale(const cv::Mat& sourceImg);
cv::Mat thresholdAuto(const cv::Mat& sourceImg);

cv::Mat rotation(const cv::Mat& sourceImg, int angle);
cv::Mat resize(const cv::Mat& sourceImg, const int& maxSize);
cv::Mat rollingBall(const cv::Mat& sourceImg);
cv::Mat Hough(const cv::Mat& sourceImg)

bool modePaysage(const cv::Mat& sourceImg);
int determinateThreshold(const cv::Mat& sourceImg);
cv::Mat calculHistogram(const cv::Mat& sourceImg);

#endif //CODEBARRES_PREPROCESS_H
