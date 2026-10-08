#include <stdio.h>
#include <stdlib.h>

int findmin(int* L, int n){
    int min = *L;
    for(int i = 0; i < n; i++){
        if(min > *(L+i))
            min = *(L+i);
    }
    return min;
}

void delete(int* L, int min, int n){
    for(int i = 0; i < n; i++){
        if(min == *(L+i))
            *(L+i) = *(L+n-1);
    }
}

int main(void){
    int n = 0;
    scanf("%d", &n);
    int* L = (int* )malloc(n * sizeof(int ));
    if(L == NULL){
        free(L);
        return -1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d",L+i);
    }
    printf("%d\n",findmin(L, n));
    delete(L, findmin(L, n), n);
    for(int i = 0; i < n-1; i++){
        printf("%d",*(L+i));
        if(i < n-2)
            putchar(' ');
    }
    free(L);
    return 0;
}

