#include <stdio.h>

void delete(int* L, int length, int m, int n){
    int i = 0;
    int newlength = length-n+m-1;
    for(i = m;i < newlength; i++){
        *(L+i) = *(L+i+n-m+1);
    }
    for(int i = 0;i < newlength-1;i++){
        printf("%d ",*(L+i));
    }
    printf("%d",*(L+newlength-1));
}
int main(void){
    int length,m,n;
    scanf("%d",&length);
    int L[length];
    for(int i = 0;i < length-1;i++)
        scanf("%d ",(L+i));
    scanf("%d",(L+length-1));
    scanf("%d%d",&m,&n);
    delete(L,length,m,n);
}




