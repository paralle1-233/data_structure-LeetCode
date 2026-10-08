#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef char SElemType;

/*定义链表栈*/
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;

//初始化链表
Status InitStack(LinkStack *z){
    *z=NULL;
    return OK;
}

//判定栈是否为空
Status StackEmpty(LinkStack y){
    if(y == NULL)
        return TRUE;
    else
        return FALSE;
}

//入栈
Status Push(LinkStack* x, SElemType w){
    LinkStack p = malloc(sizeof(LinkStack));
    if(p == NULL)
        return ERROR;
    p->data = w;
    p->next = *x;
    *x = p;
    return OK;
}

//出栈
Status Pop(LinkStack* v, SElemType* u){
    if(*v == NULL) return ERROR;
    LinkStack p = *v;
    *u = p->data;
    *v = p->next;
    free(p);
    return OK;
}

//获取栈顶元素
Status GetTop(LinkStack t, SElemType* s){
    if(t != NULL)
        *s = t->data;
    return OK;
}

//检查两个括号是否匹配
Status match(char element_l, char element_r){
  if (element_l == '('){
    if (element_r == ')'){
      return TRUE;
    }
    else{
      return FALSE;
    }
  }
  else if (element_l == '['){
     if (element_r == ']'){
        return TRUE;
     }
     else{
       return FALSE;
     }
  }
  else if (element_l == '{'){
    if (element_r == '}'){
      return TRUE;
    }
    else{
      return FALSE;
    }
  }
  else{
    exit(0);
  }
}


int main(){
  LinkStack S;
  int i = 0;
  char e;
  int lenth = 0;
  char str[MAXSIZE];
  if(ERROR==InitStack(&S)){
    printf("Initation failed.\n");
    return 0;
  }
  
  scanf("%s", str);//输入一串括号
  lenth = strlen(str);
  for (i = 0; i < lenth; i++){
    switch (str[i]){
      case '(':
      case '[':
      case '{':
        if(ERROR==Push(&S, str[i])){
          printf("Push operation failed.\n");
          return 0;
        }
        break;
      case ')':
      case ']':
      case '}':
        if (TRUE == StackEmpty(S)){
          printf("右括号多余\n");
          exit(0);
        }
        else{
           GetTop(S, &e);
           if (TRUE == match(e, str[i]) ){
             Pop(&S, &e);
           }
           else{
             printf("左右括号不匹配\n");
             exit(0);
           }
         }
         break;
       default:
         exit(0);
     }
  }
  if (TRUE == StackEmpty(S)){
    printf("括号匹配\n");
  }
  else{
    printf("左括号多余\n");
    exit(0);    
  }
  return 0;
}
