/*************************************************************************
	> File Name: test.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年10月24日 星期六 09时54分41秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b) \
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "_haizei_" #b);\
}\
void a##_haizei_##b()
//1st bug:重复定义的问题，解决：中间加字符_haizei_

#define EXPECT_EQ(a, b) \
printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False");


typedef void (*TestFuncT)();
struct Function {
    TestFuncT func;
    const char *str;
};



int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
//没懂：光哥说执行add_function()前面不加a##_haizei_##b的声明会报错   
//没懂：为什么这个add_function()的声明也在下面，但是14行却能执行？


#endif
