#include <pic.h>

int Count = = 0;

void main()
{
    TMPRO = 0;
    TOCS = 0;
    TOSE = 0;
    PSA = 0;
    PS0 = 1;
    PS1 = 1;
    PS2 = 1;

    while (1)
    {
        while (!TOIF)
        {
        };

        TOIF = 0;
        Count++;
        if (Count == 15)
        {
            Count = 0;
        }
    }
}