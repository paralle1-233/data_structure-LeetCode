#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int num = 0;
	int option = 0;

	lst* L = init_list();

	printf("put in the number of nodes: ");
	scanf("%d", &num);

	printf("insert from head or tail? \n[1]head\n[2]tail\n: ");
	scanf("%d", &option);
	if(option == 1){	
		createlst_head(L, num);
	};
	if(option == 2){
		createlst_rear(L, num);
	};

	printf("List setup OK!");
	printf("next option\n[1]insert\n[2]locate\n[3]delete\n: ");
	scanf("%d", &option);
	return 0;
}

