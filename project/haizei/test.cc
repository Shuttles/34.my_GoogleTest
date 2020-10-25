#include <haizei/test.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int func_cnt = 0;
Function func_arr[100];//全局存储
struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++){
        printf(GREEN("[====RUN====]") RED(" %s\n"), func_arr[i].str);
        haizei_test_info.total = haizei_test_info.success = 0;
        func_arr[i].func();
        double rate =  100.0 * haizei_test_info.success / haizei_test_info.total;

        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) {  //浮点数无法精确比较是否相等
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(
            GREEN("  ]") 
            " success : %d      total : %d\n\n\n",
            haizei_test_info.success,
            haizei_test_info.total
        );
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {//存储测试用例信息
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
    return ;
}
