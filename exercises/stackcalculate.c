#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;

/*定义数字链表栈*/
typedef struct StackNode{
    int data;
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
Status Push(LinkStack* x, int w){
    LinkStack p = malloc(sizeof(LinkStack));
    if(p == NULL)
        return ERROR;
    p->data = w;
    p->next = *x;
    *x = p;
    return OK;
}

//出栈
Status Pop(LinkStack* v, int* u){
    if(*v == NULL) return ERROR;
    LinkStack p = *v;
    *u = p->data;
    *v = p->next;
    free(p);
    return OK;
}

//获取栈顶元素
Status GetTop(LinkStack t, int* s){
    if(t != NULL)
        *s = t->data;
    return OK;
}

//定义算符链栈
typedef struct OpLinkStack{
    char operation;
    struct OpLinkStack* next;
}*OpLinkStack,OpStackNode;

//初始化
Status InitOpStack(OpLinkStack* S){
    *S = NULL;
    return OK;
}

//判断非空
Status OpStackEmpty(OpLinkStack S){
    if(S == NULL)
        return TRUE;
    else
        return FALSE;
}

//入栈
Status PushOpStack(OpLinkStack* S, char c){
    OpLinkStack p = (OpLinkStack )malloc(sizeof(OpLinkStack));
    if(p == NULL) return ERROR;
    p->operation = c;
    p->next = *S;
    *S = p;
    return OK;
}

//出栈
Status PopOpStack(OpLinkStack* S, char* c){
    if(S == NULL) return ERROR;

    OpLinkStack p = NULL;
    p = *S;
    *c = p->operation;
    *S = p->next;
    free (p);
    return OK;
}

//获取栈顶
Status OpGetTop(OpLinkStack S, char* c){
    if(S == NULL) return ERROR;
    
    *c = S->operation;
    return OK;
}

int Priority(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

int Calculate(int a, int b, char op){
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
    return 0;
}

Status CalculateTop(LinkStack *NumStack, OpLinkStack *OpStack){
    int a;
    int b;
    int result;
    char op;
    
    if(Pop(NumStack, &b) == ERROR) return ERROR; 
    if (Pop(NumStack, &a) == ERROR) return ERROR; 
    if (PopOpStack(OpStack, &op) == ERROR) return ERROR;
    
    result = Calculate(a, b, op);
    
    return Push(NumStack, result);
}

int main(void){

    LinkStack NumStack;
    OpLinkStack OpStack;
    char c;

    InitStack(&NumStack);
    InitOpStack(&OpStack);

    while((c = getchar()) != '#'){
        if(c == ' ' || c == '\n')
            continue;
        if(c >= '0' && c <= '9'){
            int data = 0;
            
            while(c >= '0' && c <='9'){
                data = data * 10 + (c - '0');
                c = getchar();
            }
        Push(&NumStack, data);

        if(c == '#')
            break;
        }

        if(c == '('){
            PushOpStack(&OpStack, c);
            continue;
        }
        
        if(c == ')'){
            char top;
            while(OpGetTop(OpStack, &top)
                    && top != '('){
                    CalculateTop(&NumStack, &OpStack);    
            }
            PopOpStack(&OpStack, &top);
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/'){
            char top;
            
            while(!OpStackEmpty(OpStack)){
                OpGetTop(OpStack, &top);
                if(top == '(')
                    break;
                if(Priority(top) < Priority(c))
                    break;
                CalculateTop(&NumStack,&OpStack);
            }
            PushOpStack(&OpStack, c);
            continue;
        }
    }

    while(!OpStackEmpty(OpStack)){
        CalculateTop(&NumStack, &OpStack); 
    } 
    /* 最终结果 */ 
     
    int result;
    Pop(&NumStack, &result);
    printf("结果是: %d\n", result); 
     
    return 0; 
}



