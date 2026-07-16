#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void state_machine(state state, lst* L){

	int elem = 0;
	int index = 0;
	lst* p = NULL;
	
	if(state == inserting){
		printf("put in index and elem: ");
		scanf("%d %d", &index, &elem);
		insert(L, index, elem);
	}
	if(state == locating){
		printf("put in elem: ");
		scanf("%d", &elem);
		p = locate_list(*L, elem);
		if(p){
			printf("pointer name is set as p. ");
		}
	}
	if(state == searching){
		printf("which node are you searching for? ");
		scanf("%d", &index);
		printf("the elem of node%d is %d\n", index, get_data(*L, index, elem));
	}
	if(state == deleting){
		printf("put in elem: ");
		scanf("%d", &elem);
		list_delete(L, elem);
	}	
	if(state == traversing){
		traverse_list(L);
	}
}
int main(void){

	int num = 0;
	int option = 0;

	state state = 0;

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

	printf("List setup OK!\n");
		
	while(state != 6){
		printf("next option\n[1]insert\n[2]locate\n[3]search\n[4]delete\n[5]traverse\n[6]leave\n: ");
		scanf("%d", &state);
		state_machine(state, L);
	}
	return 0;
}

