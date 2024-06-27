#include <stdio.h>

int main()
{

    int n, v;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v);
        sum += v;
    }
    if (sum <= 0)
    {
        sum = sum * -1;
    }
    printf("%lld\n", (sum));

    return 0;
}