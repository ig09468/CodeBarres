//
// Created by meynadier on 18/02/19.
//

#ifndef CODEBARRES_PROCESS_H
#define CODEBARRES_PROCESS_H


#include <core/mat.hpp>
#include <iostream>
#include "EAN.h"

using namespace std;

int readingEAN(cv::Mat& barCode, const int& number);


int searchStart(const cv::Mat& sourceImg);
int convertByteToEAN(const vector<int>& convert);
bool isBlack(const int& value);


#endif //CODEBARRES_PROCESS_H
