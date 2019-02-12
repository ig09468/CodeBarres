#include <iostream>
#include "test/TestPreProcess.h"


int main() {
    string src = "/home/meynadier/ProjectImg/img/ROTATE.jpg";
    TestPreProcess *test = new TestPreProcess(src, 512);
    test->test();
    return 0;
}