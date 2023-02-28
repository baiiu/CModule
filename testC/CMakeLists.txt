cmake_minimum_required(VERSION 3.17)
project(testC)

set(CMAKE_C_STANDARD 11)

add_executable(
        testC
        main.c
        common.h

        hello.c hello.h
        animal.c animal.h
        hookFunction.c hookFunction.h
        testStr.c testStr.h
        testSocket.c testSocket.h
        testStruct.c testStruct.h
        testDefine.c testDefine.h
        testSimple.c testSimple.h

        testStack.c testStack.h
        testVector.cpp testVector.h
        testCPP.cpp testCPP.h
        testCommon.c testCommon.h
        testParseUrl.c testParseUrl.h
        testVoid*.c testVoid*.h
        testDNS.c testDNS.h
        testPointer.c testPointer.h
        testJump.c testJump.h
)