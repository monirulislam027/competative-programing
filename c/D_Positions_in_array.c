#include <stdio.h>

int main()
{

    int n, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (value <= 10)
        {
            printf("A[%d] = %d\n", i, value);
        }
    }

    return 0;
}