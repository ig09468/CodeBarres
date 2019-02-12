//
// Created by meynadier on 12/02/19.
//

#ifndef CODEBARRES_TEST_H
#define CODEBARRES_TEST_H


#include <core/mat.hpp>
#include "../PreProcess.h"
#include <iostream>

using namespace std;

class TestPreProcess {
public:
    explicit TestPreProcess(string &srcImg, int maxSize);
    virtual ~TestPreProcess();
    void test();
private:
    void testGreyscale();
    void testResize();
    void testThreshold();
    void testOpen();

    cv::Mat img;
    int maxSize;
};


#endif //CODEBARRES_TEST_H
