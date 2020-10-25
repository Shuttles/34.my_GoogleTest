#include <haizei/test.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <haizei/linklist.h>
int func_cnt = 0;
//Function func_arr[100];//全局存储
struct Function func_head, *func_tail = &func_head;//链表
struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p != NULL; p = p->next) {
        struct Function *f = Head(p, struct Function, p); 
        printf(GREEN("[====RUN====]") RED(" %s\n"), f->str);
        haizei_test_info.total = haizei_test_info.success = 0;
        f->func();
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
    struct Function *temp = (struct Function *)calloc(1, sizeof(struct Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
}
