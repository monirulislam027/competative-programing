#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long count_before_one(int arr[], int size)
{
    int count = 0, value;
    for (int i = 0; i < size; i++)
    {

        if (*(arr + i) == 1)
            return count;
        count++;
    }
    return 0;
}

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    long count = count_before_one(arr, n);
    printf("%d", count);
    return 0;
}
