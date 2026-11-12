#include <stdio.h>
#include <string.h>

int main()
{
    char s[300001];
    int i, j, k, len, maxLen = 0, maxPos = 0;

    scanf("%300000s", s);
    len = strlen(s);

    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            for (k = 0; j + k < len && s[i + k] == s[j + k]; k++)
            {
                if (k + 1 > maxLen)
                {
                    maxLen = k + 1;
                    maxPos = i;
                }
            }
        }
    }

    if (maxLen == 0)
        printf("没有最长重复子串");
    else
    {
        for (i = 0; i < maxLen; i++)
            printf("%c", s[maxPos + i]);
        printf("\n");
    }

    return 0;
}
