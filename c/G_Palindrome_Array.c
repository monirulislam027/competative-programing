#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    long long int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int isPalindrome = 1;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (arr[i] != arr[j])
        {
            isPalindrome = 0;
            break;
        }

        i++;
        j--;
    }

    if (isPalindrome == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}