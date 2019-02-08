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

cv::Mat thresholdConfig(const cv::Mat& src, const int& seuil, const int& maxVal);
cv::Mat openImg(string& src);
cv::Mat rotation(const cv::Mat& sourceImg);
bool modePaysage(const cv::Mat& sourceImg);


#endif //CODEBARRES_PREPROCESS_H
