//
// Created by meynadier on 29/03/19.
//

#ifndef CODEBARRES_TESTPROCESS_H
#define CODEBARRES_TESTPROCESS_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "../Process.h"

class TestProcess {
private:
    cv::Mat img;
    bool testSearchRatio();
    bool testIsBlack();
    bool testSearchFirstDelimiter();
    bool testSearchStartBarCode();
    bool testReadingEAN();
    bool testConvertToEAN();
public:
    TestProcess();
    virtual ~TestProcess();
    void start();
};


#endif //CODEBARRES_TESTPROCESS_H
