/*************************************************************************
	> File Name: main.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年10月23日 星期五 22时18分14秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
//#include <gtest/gtest.h>
#include <haizei/test.h>
using namespace std;

int add(int a, int b) {
    return a + b;
} 

TEST(testFunc, add) {
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_NE(add(5, 3), 9);
    EXPECT_GT(add(6, 7), 10);
    EXPECT_LE(add(6, 7), 13);
    EXPECT_GT(add(6, 7), 20);
}

TEST(testFunc, add2) {
    EXPECT_EQ(add(100, 200), 300);
    EXPECT_NE(add(100, 200), 301);
    EXPECT_EQ(add(6, 9), 15.3);
}

TEST(test, Funcadd) {
    EXPECT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(6, 7), 15);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}

