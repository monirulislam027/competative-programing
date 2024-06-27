#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[n], b[n], temp, diff;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
            b[j] = a[j];
        }

        // ascending  sort
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n - k - 1; l++)
            {

                if (b[l] > b[l + 1])
                {
                    temp = b[l];
                    b[l] = b[l + 1];
                    b[l + 1] = temp;
                }
            }
        }

        for (int l = 0; l < n; l++)
        {
            diff = abs(a[l] - b[l]);
            printf("%d ", diff);
        }
        printf("\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
