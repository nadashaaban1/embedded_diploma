#include <stdio.h>

int main()
{
    char alphabet[27];
    int base = 65;
    char *p = alphabet;
    for (int i = 0; i < 26; i++)
    {
        *p = base+i;
        p++;
    }

    for (int i = 0; i < 26; i++)
    {
        p=&alphabet[i];
        printf("%c ", *p);
    }
    return 0;
}