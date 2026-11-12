#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char s[100001];
    scanf("%d", &n);

    while (n--)
    {
        int count[26] = {0};
        int max = 0, index = 0;

        scanf("%100000s", s);

        for (i = 0; s[i] != '\0'; i++)
            count[s[i] - 'a']++;

        for (i = 0; i < 26; i++)
        {
            if (count[i] > max)
            {
                max = count[i];
                index = i;
            }
        }

        printf("%c %d\n", 'a' + index, max);
    }

    return 0;
}
