#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n, a, b, c, missing;
    long long int m;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %d %d %d", &m, &a, &b, &c);

        if (m % (a * b * c) == 0)
        {
            missing = m / (a * b * c);
            printf("%d\n", missing);
        }
        else
        {
            printf("-1\n");
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
