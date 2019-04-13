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
        src = "/home/meynadier/ProjectImg/img/etp2/E2.jpg";
    }
    //TestProcess testProcess = TestProcess();
    //testProcess.start();
    //TestPreProcess test = TestPreProcess(src, 1000);
    //test.test();


    return 0;
}