#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];

    while (fgets(s, sizeof(s), stdin))
    {
        s[strcspn(s, "\r\n")] = '\0';

        if (strcmp(s, "ENDOFINPUT") == 0)
            break;

        if (strcmp(s, "START") == 0)
        {
            fgets(s, sizeof(s), stdin);
            for (int i = 0; s[i] != '\0'; i++)
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = (s[i] - 'A' + 21) % 26 + 'A';
            }
            printf("%s", s);

            fgets(s, sizeof(s), stdin);
        }
    }

    return 0;
}
