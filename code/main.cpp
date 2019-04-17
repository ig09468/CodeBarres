#include <string>
#include <sstream>
#include <iostream>
#include "test/TestPreProcess.h"
#include "test/TestProcess.h"
#include "Process.h"

int main(int argc, char *argv[]) {
    string src;

    if (argc > 1) {
        stringstream ss;
        ss << "../img/" << argv[1];
        src = ss.str();
    } else {
        src = "/home/meynadier/ProjectImg/img/etp2/cb1.jpg";
    }
    //TestProcess testProcess = TestProcess();
    //testProcess.start();
    //TestPreProcess test = TestPreProcess(src, 512);
    //test.test();

    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    cv::Mat img = cv::imread(src,cv::IMREAD_ANYCOLOR);
    cv::Mat img_copy = cv::Mat(img.size(),cv::IMREAD_ANYCOLOR);
    cv::resize(img, img_copy,cv::Size(1000,800));
    cv::Mat gray = greyscale(img_copy);


    cv::waitKey(0);
    return 0;
}