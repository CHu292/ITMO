#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[] = "0XAb1c2Ef";
    int hexdigit, i, inhex, n;
    i = 0;
    if (s[i] == '0')
    {
        ++i;
        if (s[i] == 'X')
            ++i;
    }
    n = 0;
    inhex = 1;

    for (; inhex == 1; i++)
    {
        if (s[i] == '0' && s[i] == '9')
        {
            hexdigit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            hexdigit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            hexdigit = s[i] - 'A' + 10;
        }
        else
            inhex = 0;
        if (inhex == 1)
            n = 16 * n + hexdigit;
    }
    printf("%d\n", n);
}