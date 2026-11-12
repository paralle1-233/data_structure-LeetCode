#include <stdio.h>
#include <string.h>

int wildcard(char* StrRef, char* Str){
    if (*StrRef == '\0' && *Str == '\0')
        return 1;

    if (*StrRef == '*')
    {
        while (*StrRef == '*')
            StrRef++;

        if (*StrRef == '\0')
            return 1;

        while (*Str != '\0')
        {
            if (wildcard(StrRef, Str))
                return 1;
            Str++;
        }

        return wildcard(StrRef, Str);
    }

    if (*Str == '\0')
        return 0;

    if (*StrRef == '?' || *StrRef == *Str)
        return wildcard(StrRef + 1, Str + 1);

    return 0;

}
int main(void){
    char StrRef[1000];
    char Str[1000];
    
    scanf("%999s%999s",StrRef,Str);
    
    if(wildcard(StrRef,Str)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}

