#include <stdio.h>
#include <limits.h>

int main()
{

    int n, min = INT_MAX, index, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (value < min)
        {
            min = value;
            index = i;
        }
    }

    printf("%d %d", min, index + 1);

    return 0;
}