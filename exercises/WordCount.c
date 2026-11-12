#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100000
#define WORD_LEN 100

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

Word words[MAX_WORDS];
int wordCount = 0;

void AddWord(char *s)
{
    int i;
    for (i = 0; i < wordCount; i++)
    {
        if (strcmp(words[i].word, s) == 0)
        {
            words[i].count++;
            return;
        }
    }

    strcpy(words[wordCount].word, s);
    words[wordCount].count = 1;
    wordCount++;
}

int Compare(const void *a, const void *b)
{
    Word *x = (Word *)a;
    Word *y = (Word *)b;

    if (x->count != y->count)
        return y->count - x->count;

    return strcmp(x->word, y->word);
}

int main()
{
    FILE *fp = fopen("article.txt", "r");
    char s[WORD_LEN];
    int ch, i = 0;

    if (fp == NULL)
        return 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha((unsigned char)ch))
        {
            if (i < WORD_LEN - 1)
                s[i++] = tolower((unsigned char)ch);
        }
        else if (i > 0)
        {
            s[i] = '\0';
            AddWord(s);
            i = 0;
        }
    }

    if (i > 0)
    {
        s[i] = '\0';
        AddWord(s);
    }

    fclose(fp);

    qsort(words, wordCount, sizeof(Word), Compare);

    for (i = 0; i < wordCount; i++)
        printf("%s %d\n", words[i].word, words[i].count);

    return 0;
}
