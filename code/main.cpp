#include <string>
#include <sstream>
#include <iostream>
#include "test/TestPreProcess.h"


int main(int argc, char *argv[]) {
    string src;

    if (argc > 1) {
        stringstream ss;
        ss << "../img/" << argv[1];
        src = ss.str();
    } else {
        src = "/home/meynadier/ProjectImg/img/ROTATE.jpg";
    }
    TestPreProcess *test = new TestPreProcess(src, 512);
    test->test();
    return 0;
}