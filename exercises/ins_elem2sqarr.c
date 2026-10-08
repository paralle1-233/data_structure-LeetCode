#include <stdio.h>
#include <stdlib.h>

void insert(int* L, int length,int elem){
    int i;
    for(i = length - 1; i >= 0 && elem < *(L+i); i--){
        *(L+i+1) = *(L+i);
    }
    *(L+i+1) = elem;
}

int main(void){
    int length = 0;
    int elem = 0;
    scanf("%d",&length);
    int* L = (int* )malloc((length + 1) * sizeof(int ));
    if(L == NULL)
        return -1;
    for(int i = 0; i < length; i++){
        scanf("%d",L+i);
    }
    scanf("%d", &elem);
    insert(L, length, elem);
    for(int i = 0; i <= length; i++){
        if(i != length){
            printf("%d ",*(L+i));
        }else{
        printf("%d\n",*(L+i));
        }
    }
    free(L);
    return 0;
}

