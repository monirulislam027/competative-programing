#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int t, pathan, tiger;
    long int n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {

        scanf("%ld", &n);
        char str[n];
        scanf("%s", str);
        pathan = 0;
        tiger = 0;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == 'T')
                tiger++;
            else if (str[j] == 'P')
                pathan++;
        }
        if (pathan == tiger)
        {
            printf("Draw\n");
        }
        else if (tiger > pathan)
        {
            printf("Tiger\n");
        }
        else
        {
            printf("Pathaan\n");
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
