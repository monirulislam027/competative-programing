#include <stdio.h>

int main()
{

    int n, spaceCount, hashCount;
    char printElm;
    scanf("%d", &n);
    int i = 0;
    while (i < n)
    {
        spaceCount = n - 1 - i;
        hashCount = (2 * i) + 1;
        for (int i = 0; i < spaceCount; i++)
        {
            printf(" ");
        }

        if (i % 2 == 0)
            printElm = '#';
        else
            printElm = '-';
        for (int i = 0; i < hashCount; i++)
        {
            printf("%c", printElm);
        }
        printf("\n");
        i++;
    }

    i = n - 2;
    while (i >= 0)
    {
        spaceCount = n - 1 - i;
        hashCount = (2 * i) + 1;
        for (int i = 0; i < spaceCount; i++)
        {
            printf(" ");
        }

        if (i % 2 == 0)
            printElm = '#';
        else
            printElm = '-';
        for (int i = 0; i < hashCount; i++)
        {
            printf("%c", printElm);
        }
        printf("\n");
        i--;
    }

    return 0;
}