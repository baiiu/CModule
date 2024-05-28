cmake_minimum_required(VERSION 3.17)
project(testCPP)

SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_CXX_STANDARD 11)

add_executable(testCPP
        main.cpp
        call_once.cpp call_once.h
        common.h
        testConst.cpp testConst.h
        testStatic.cpp testStatic.h
        teststring.cpp teststring.h
        testConstructor.cpp testConstructor.h
        testPerson.cpp testPerson.h
        testDynamic.cpp testDynamic.h
        testThread.cpp testThread.h
        testEnum.cpp testEnum.h
        sps/testsps.cpp sps/testsps.h
        sps/spspps.cpp sps/spspps.h
        testQueue.cpp testQueue.h
        testReference.cpp testReference.h
        houjie/hjOperator-test.cpp houjie/hjOperator.h
        houjie/hjString.cpp houjie/hjString.h
        houjie/hjStaic.cpp houjie/hjStaic.h
        houjie/hjTemplate.cpp houjie/hjTemplate.h
        houjie/hjVirtual.cpp houjie/hjVirtual.h
        smart_ptr/multiTai.cpp smart_ptr/multiTai.h
        testSmartPtr.cpp testSmartPtr.h
        #        singleton/testSingletonWrong.cpp
        singleton/testSingleton.cpp
        singleton/testSingleton.h testSize.cpp testSize.h testVirtualPtr.h testVirtualPtr.cpp testVirtualSize.cpp testSem.cpp testSem.h testTime.cpp testTime.h
        cpp_primer/Message.cpp cpp_primer/Message.h cpp_primer/Folder.cpp cpp_primer/Folder.h
        cpp_primer/StrVec.cpp cpp_primer/StrVec.h cpp_primer/smartPtr_deleter.cpp cpp_primer/smartPtr_deleter.h
        smart_ptr/smart_unique_ptr.h smart_ptr/smart_shared_ptr.h
        effectivecpp/passByReferenceConst.cpp effectivecpp/passByReferenceConst.h

        )