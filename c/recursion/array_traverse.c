
#include <stdio.h>

void traverse(int arr[], int n, int i)
{
    if (i == n)
        return;
    printf("%d\n", arr[i]);
    traverse(arr, n, i + 1);
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    traverse(arr, 5, 0);
}