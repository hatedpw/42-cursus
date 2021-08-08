#include "libft.h"

int ft_atoi(const char *str)
{
    int             ret;
    long long   value;

    ret = 1
    value = 0;
    while (*str == ' ' || *str == '\f' || *str == '\n'
        || *str == '\r' || *str == '\t' || *str == '\v')
        str++;
    while (*str == '+' || *str == '-')
        if (*(str++)) == '-')
            ret *= -1;
    while ('0' <= *str && *str <'9')
    {
        ret *= 10;
        ret += (sign * (*(str++) - '0'));
    }
    return (ret);
}