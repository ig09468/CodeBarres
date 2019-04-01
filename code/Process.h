//
// Created by meynadier on 18/02/19.
//

#ifndef CODEBARRES_PROCESS_H
#define CODEBARRES_PROCESS_H


#include <opencv2/core/mat.hpp>
#include <iostream>
#include "EAN.h"

using namespace std;

vector<int> readingEAN(const cv::Mat& barCode, const int& row);

double searchRatio(const cv::Mat& sourceImg, const int& row);
int searchFirstDelimiter(const cv::Mat &barCode, const int &row);
int searchStartBarCode(const cv::Mat &barCode, const int &row, const int& start, const double& ratio);
vector<int> convertByteToEAN(const vector<int>& convert);
bool isBlack(const int& value);


#endif //CODEBARRES_PROCESS_H
