#include <stdio.h>

int main()
{

    int n, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (value == 0)
        {
            printf("0 ");
        }
        else if (value >= 1)
        {
            printf("1 ");
        }
        else
        {
            printf("2 ");
        }
    }

    return 0;
}