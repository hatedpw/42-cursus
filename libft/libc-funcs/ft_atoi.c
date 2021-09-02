#include "libft.h"
/* I hate atoi, this function caused me so many issues during piscine. 
* take a string of char that are meant to be num convert into int. 
* create 3 variables, ret holds result, value is to turn neg.
* idx is counter for array. 
* intial check for spacing at beginning of str. 
* check if neg or positive. 
* if neg make value = -1 to get result. 
* then convert char to int if digit. 
* keep looping til find char that is not number. 
* return the ret * value. added (int) to verify that returns as an int. 
*/
int	ft_atoi(const char *str)
{
    int    ret;
    int    sign;

    ret = 0;
    sign = 1;
    while (*str == '\t'
        || *str == '\n'
        || *str == '\v'
        || *str == '\f'
        || *str == '\r'
        || *str == ' ')
        ++str;
    if (*str == '+' || *str == '-')
    {
        if (*(str) == '-')
            sign *= -1;
		str++;
    }
    while ('0' <= *str && *str <= '9')
    {
        ret *= 10;
        ret += (sign * (*(str++) - '0'));
    }
    return (ret);
} 
