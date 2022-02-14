cmake_minimum_required(VERSION 3.17)
project(testCPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(testCPP main.cpp call_once.cpp call_once.h common.h testConst.cpp testConst.h testStatic.cpp testStatic.h teststring.cpp teststring.h testConstructor.cpp testConstructor.h testPerson.cpp testPerson.h testDynamic.cpp testDynamic.h testThread.cpp testThread.h testEnum.cpp testEnum.h sps/testsps.cpp sps/testsps.h sps/spspps.cpp sps/spspps.h testQueue.cpp testQueue.h testReference.cpp testReference.h houjie/testOperator-test.cpp houjie/testOperator.h houjie/testString.cpp houjie/testString.h)