#include <stdio.h>

int main()
{

    int n, found = -1;
    long long int x;
    scanf("%d", &n);
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    scanf("%lld", &x);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            found = i;
            break;
        }
    }

    printf("%d\n", found);

    return 0;
}