/*************************************************************************
	> File Name: linklist.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年10月25日 星期日 23时12分46秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

//链表外骨骼
#define offset(T, name) (long long)(&(((T*)(0))->name))
#define Head(p, T, name) ((T *)(((char *)p) - offset(T, name)))

struct LinkNode {//链表节点
    struct LinkNode *next;
};


#endif
