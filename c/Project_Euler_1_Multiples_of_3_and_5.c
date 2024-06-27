#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        scanf("%d", &n);
        int n1 = (n - 1) / 3;
        long long int val1 = (3 * n1 * (n1 + 1) * 0.5);
        int n2 = (n - 1) / 5;
        long long int val2 = (5 * n2 * (n2 + 1) * 0.5);

        int n3 = (n - 1) / 15;
        long long int val3 = (15 * n3 * (n3 + 1) * 0.5);
        long long int sm = val1 + val2 - val3;

        printf("%lld\n", sm);
    }
    return 0;
}
