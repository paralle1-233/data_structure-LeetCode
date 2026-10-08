#include <stdio.h>
#include <stdlib.h>

void swaparr(int* L, int length, int m, int n){
    int* l = (int* )malloc(m * sizeof(int ));
    for(int i = 0; i < m; i++){
        *(l+i) = *(L+i);
    }
    for(int i = m; i < length; i++){
        *(L+i-m) = *(L+i);
    }
    for(int i = n; i < length; i++){
        *(L+i) = *(l+i-n);
    }
}

int main(void){
    int length = 0;
    int m,n;
    scanf("%d %d", &m, &n);
    length = m + n;
    int* L = (int* )malloc(length * sizeof(int));
    if(L == NULL)
        return -1;
    printf("The original array is:\n");
    for(int i = 0; i < length; i++){
        scanf("%d",L+i);
        printf("%d",*(L+i));
        if(i != length)
            printf(" ");
    }
    putchar('\n');
    swaparr(L, length, m, n);
    printf("The swapped array is:\n");
    for(int i = 0; i < length; i++){
        printf("%d", *(L+i));
        if(i != length-1)
            printf(" ");
    }
    putchar('\n');
    free(L);
    return 0;
}
