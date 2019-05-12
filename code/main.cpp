#include <string>
#include <sstream>
#include <iostream>
#include "test/TestPreProcess.h"
#include "test/TestProcess.h"
#include "Process.h"
#include "PreProcess.h"
#include <unistd.h>

static string TEST_IMAGE = "etp2/2.jpg";
static string SEP = "/";

#ifdef _WIN32
    SEP = '\\';
#endif

int main(int argc, char *argv[]) {
    string src = "/home/meynadier/ProjectImg/img/etp2/";
    string save = "/home/meynadier/ProjectImg/img/result/";
    start(src, save,1000);

    cv::waitKey(0);
    return 0;
}