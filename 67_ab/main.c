#include <string.h>
#include <stdlib.h>

#define addBinary add_binary

char *add_binary(char *a, char *b)
{
    short ai = strlen(a), bi = strlen(b);
    char *c = malloc(ai + bi + 1);

    char overflow = '0';
    short i = 0; --ai; --bi;
    while (ai + 1 && bi + 1)
    {
        // f(x) = !(*a + *b - 97) + '0'
        c[i] = !(!(a[ai] + overflow - 97) + b[bi] - '1') + '0';
        overflow = ((a[ai] + b[bi] + overflow - 145) > 0) + '0';

        ++i; --ai; --bi;
    }

    while (ai + 1)
    {
        c[i] = !(a[ai] + overflow - 97) + '0';
        overflow = (a[ai] + overflow == 98) + '0';

        ++i; --ai;
    }
    while (bi + 1)
    {
        c[i] = !(b[bi] + overflow - 97) + '0';
        overflow = (b[bi] + overflow == 98) + '0';

        ++i; --bi;
    }

    c[i++] = (overflow == '1') ? '1' : '\0';
    c[i] = '\0';

    c = realloc(c, i += (overflow == '1'));
    i -= 2;
    for (short k = 0; k < i; ++k, --i)
    {
        char temp = c[k];
        c[k] = c[i];
        c[i] = temp;
    }
    return c;
}