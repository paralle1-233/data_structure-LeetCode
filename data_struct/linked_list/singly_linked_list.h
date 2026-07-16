#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
typedef enum status{
	OK=0,
	ERROR,
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
lst* init_list(void);
int get_data(lst L, int i, int e);
lst* locate_list(lst L, int e);
status insert(lst* L, int i, int elem);
void createlst_head(lst* L, int n);
void createlst_rear(lst* L, int n);
void list_delete(lst* L, int elem);
void traverse_list(lst* L);
#endif

