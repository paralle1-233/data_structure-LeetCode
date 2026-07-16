#include <stdio.h>
#include <stdlib.h>

typedef enum status{
	OK=0, ERROR=1
}status;

typedef enum state{
	inserting = 1,
	locating,
	searching,
	deleting,
	traversing,
	over,
}state;

typedef struct List{
	int elem;
	struct List* next;
}lst;

lst* init_list(void){
	lst* L = (lst* )malloc(sizeof(lst));
	if(L == NULL) printf("initialization failed!\n");
	L->next = NULL;
	return L;
}//初始化结构体，创建头指针

int get_data(lst L, int i, int e){
	lst* p = NULL;
	p = &L;
	int j = 1;
	while(p->next && j <= i){
		p = p->next;
		printf("%d", j);
		++j;
	}
	if(!p || --j > i){
		return -1;
	}else{
		e = p->elem;
		return e;
	}
}//取值

lst* locate_list(lst L, int e){
	lst* p = NULL;
	p = &L;
	while(p && p->elem != e){
		p = p->next;
	}
	if(!p) return NULL;
	return p;
}//查找

status insert(lst* L, int i, int elem){
	lst* p = NULL;
	p = L;
	int j = 1;
	while(p->next && j < i){
		p = p->next;
		++j;
	}
	if(!p->next){
		lst* s = NULL;
		s = (lst* )malloc(sizeof(lst));
		if(s == NULL){
		       	printf("failed to create node!");
		}
		s->elem = elem;
		p->next = s;
		s->next = NULL;
	}else if(j > i){
		return ERROR;
	}else{
		lst* s = NULL;
		s->next = p->next;
		p->next = s;
		s->elem = elem;
	}
	return OK;
}//插入（插在第i位，包含后插的情形）

void createlst_head(lst* L, int n){
		
	for(int i = 1;i <= n;i++){
		lst* p = NULL;
		p = (lst* )malloc(sizeof(lst));
		if(p == NULL){
			printf("node creation failed!\n");
		}
		printf("put in elem of node%d: ", i);
		scanf("%d", &p->elem);
		p->next = L->next;
		L->next = p;
	}
}//前插法

void createlst_rear(lst* L, int n){

	lst* r = L;
	for(int i = 1;i <= n;i++){
		lst* p =NULL;
		p = (lst* )malloc(sizeof(lst));
		if(p == NULL){
			printf("node creation failed!\n");
		}
		printf("put in elem of node%d: ", i);
		scanf("%d", &p->elem);
		r->next = p;
		p->next = NULL;
		r = p;
	}
}//后插法

void list_delete(lst* L, int elem){
	lst* p = L;
	lst* prev = NULL;
	while(p != NULL){
		prev = p;
		p = p->next;
		if(p->elem == elem){
			prev->next = p->next;
			free(p);
		}
	}
}//删除元素值为elem的节点

void traverse_list(lst* L){
	lst* p = L;
	int i = 1;
	while(p->next){
		printf("elem of node%d: %d ", i, p->elem);
		p = p->next;
		i++;
	}
}
