#include <stdio.h>

int main()
{

    int x, p;
    scanf("%d %d", &x, &p);

    float y = (100 * p * 1.00) / (100 - x);
    printf("%0.2f", y * 1.0);

    return 0;
}