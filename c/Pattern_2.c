#include <stdio.h>

int main()
{

    int n, spaceCount;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        spaceCount = n - i;

        for (int i = 0; i < spaceCount; i++)
        {
            printf("");
        }

        for (int j = i; j > 0; j--)
        {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}