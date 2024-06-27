#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int is_palindrome(char st[])
{
    int isPalindrome = 1;
    int i = 0, j = strlen(st) - 1;
    while (i <= j)
    {
        if (st[i] != st[j])
        {
            isPalindrome = 0;
            break;
        }

        i++;
        j--;
    }
    return isPalindrome;
}

int main()
{

    int limit = 1001;
    char st[limit];

    fgets(st, limit, stdin);
    int isPalindrome = is_palindrome(st);

    if (isPalindrome == 1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }

    return 0;
}