#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int flag = 1;
    if (n != m)
    {
        flag = 0;
    }
    else
    {

        int arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j || j == n - 1 - i)
                {
                    if (arr[i][j] != 1)
                    {
                        flag = 0;
                    }
                    continue;
                }
                if (arr[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
