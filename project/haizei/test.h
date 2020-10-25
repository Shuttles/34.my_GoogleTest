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


//用来获取类型所对应的格式化字符串，比如：若是int就是%d
#define TYPE_STR(a) _Generic((a),\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld"\
)

//其实我没搞懂为什么要封装这个P宏，但是不封装的话会报错。。报错我没看懂
//printf(YELLOW_HL("%d") " VS " YELLOW_HL("%d"), _a, _b); 这么写虽然不报错，但是只能输出整型，所以必须写TPYE宏
//printf(YELLOW_HL(TYPE(_a)) " VS " YELLOW_HL(TYPE(_b)), _a, _b);这么写就会报错，但是不懂为什么
//关于泛型宏，见1.CProgrammingLearning
#define P(a, color) {\
    char fmt[1000];\
    sprintf(fmt, color("%s"), TYPE_STR(a));\
    printf(fmt, a);\
}

#define EXPECT(a, b, cmp) {\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    haizei_test_info.total += 1;\
    printf(GREEN("[-----------]") " " #a " " #cmp " " #b);\
    printf(" %s\n", (_a)  cmp  (_b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
    if (_a cmp _b) haizei_test_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d : Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect " #a " " #cmp " " #b " actual: "));\
        printf("\n");\
    }\
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

struct FunctionInfo { //统计一个测试用例的信息
    int total, success;
};

extern struct FunctionInfo haizei_test_info;//声明外部变量,(定义在源文件test.cc中)

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
//没懂：光哥说执行add_function()前面不加a##_haizei_##b的声明会报错   
//没懂：为什么这个add_function()的声明也在下面，但是14行却能执行？


#endif
