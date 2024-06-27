#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int rowsCount = (n + 11) / 2, space, starCount;
    for (int i = 0; i < rowsCount; i++)
    {
        space = rowsCount - i - 1;
        for (int i = 0; i < space; i++)
        {
            printf(" ");
        }

        starCount = 2 * i + 1;
        for (int j = 0; j < starCount; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {

        for (int i = 0; i < 5; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
