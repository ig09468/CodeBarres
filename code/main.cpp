#include <string>
#include <sstream>
#include <iostream>
#include "test/TestPreProcess.h"
#include "test/TestProcess.h"

int main(int argc, char *argv[]) {
    string src;

    if (argc > 1) {
        stringstream ss;
        ss << "../img/" << argv[1];
        src = ss.str();
    } else {
        src = "E:/Fac/M1/S2/CodeBarres/img/before.jpg";
    }
	TestPreProcess *test = new TestPreProcess(src, 512);
    test->test();
    //TestProcess test = TestProcess();
    //test.start();
    return 0;
}