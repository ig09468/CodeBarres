#include <string>
#include <sstream>
#include <iostream>
#include "test/TestPreProcess.h"
#include "test/TestProcess.h"
#include "Process.h"
#include <unistd.h>

string TEST_IMAGE = "etp2/cb1.jpg";
string SEP = "/";

#ifdef _WIN32
    SEP = '\\';
#endif

int main(int argc, char *argv[]) {
    string src;
    stringstream ss;

    char cwd[100000];
    getcwd(cwd, sizeof(cwd));
    ss << cwd << SEP << ".." << SEP << "img" << SEP << TEST_IMAGE;
    src = ss.str();

    TestProcess process = TestProcess();
    process.start();
    TestPreProcess pre_process = TestPreProcess(src, 512);
    pre_process.test();

    return 0;
}