#include <stdio.h>
#include <stdlib.h>
#define int datatype

typedef enum status{
    success=0,
    fail=-1,
};
/* 状态值 */

typedef struct stacknode{
    datatype data;
    struct stacknode* next;
}stk;
/* 链栈存储结构
 * 数据类型为datatype */

stk* stackinit(void){
    stk* p = NULL;
    return p;
}
/* 链栈初始化
 * 返回栈顶指针 */

status push(stk* s, datatype data){
    stk* p = (stk* )malloc(sizeof(stk));
    if(!p){
        return fail;
    }
    p->data = data;
    p->next = s;
    s = p;
    free(p);
    return success;
}
/* 入栈 移动栈顶指针 */

datatype pop(stk* s){
    if(s == NULL) return fail;
    stk* p = s;
    datatype data = p->data;
    s = s->next;
    free(p);
    return data;
}
/* 出栈 释放内存 */

datatype gettop(stk* s){
    if(s != NULL){
        return s->data;
    }
}
/* 取栈顶元素 */


