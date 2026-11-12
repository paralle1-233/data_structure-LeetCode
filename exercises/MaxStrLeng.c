#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[10000];
    int seen[256] = {0};
    int left = 0, right, max = 0, c;

    scanf("%9999s", s);

    for (right = 0; s[right] != '\0'; right++) {
        c = (unsigned char)s[right];

        while (seen[c]) {
            seen[(unsigned char)s[left]] = 0;
            left++;
        }

        seen[c] = 1;

        if (right - left + 1 > max)
            max = right - left + 1;
    }

    printf("%d\n", max);

    return 0;
}
