#include <stdio.h>
#include <stdlib.h>

int main(void){
    int NUM = 25;
    int offset = 0;
    int pos = 0;
    scanf("%d",&offset);
    int** L = (int** )malloc(5 * sizeof(int* ));
    if(L == NULL){
        free(L);
        return -1;
    }
    for(int i = 0;i < 5; i++){
        *(L+i) = (int* )malloc(5 * sizeof(int ));
        for(int j = 0; j < 5; j++){
            scanf("%d",(*(L+i)+j));
        }
    }

    for(int i = 0;i < 5; i++){
        for(int j = 0; j < 5; j++){
            pos = (5*i+j+1) + offset - 1;
            printf("%d",*(*(L+(pos % NUM) / 5)+(pos % 5)));
            if(j != 4)
                putchar(' ');
        }
        putchar('\n');
    }
    free(L);
}

