#include "libft.h"

char    *ft_strncat(char *s1, const char *s2, size_t n)
{
    int i;
    char    *ptr;

    i = 0;
    ptr = dest;
    while (*ptr)
        ++ptr;
    while (*src && i < n)
    {
        *ptr = *src;
        ++src;
        ++ptr;
        ++i;
    }
    *ptr = 0;
    return (dest);
}