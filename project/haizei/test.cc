#include <haizei/test.h>
#include <stdio.h>
#include <string.h>

int func_cnt = 0;
Function func_arr[100];//全局存储

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++){
        printf(GREEN("[====RUN====]") RED(" %s\n"), func_arr[i].str);
        func_arr[i].func();
        printf("Run End!\n");
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {//存储测试用例信息
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
    return ;
}
