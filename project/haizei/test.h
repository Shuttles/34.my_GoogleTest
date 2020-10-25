/*************************************************************************
	> File Name: test.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年10月24日 星期六 09时54分41秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)
#define RED(a) COLOR(a, 31)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define RED_HL(a) COLOR_HL(a, 31)

#define TEST(a, b) \
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()
//1st bug:重复定义的问题，解决：中间加字符_haizei_


#define EXPECT(a, b, cmp) {\
    printf(GREEN("[-----------]") #a " " #cmp " " #b);\
    printf(" %s\n", (a)  cmp  (b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)

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
