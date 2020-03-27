#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

int     list(int num, ...)
{
    va_list args;
    int     value;
    int     argument;
    int     i;

    i = 0;
    va_start(args, num);
    while (i < num)
    {
        value = va_arg(args, int);
        printf("Here is the current variable:%d\n", value);
        i++;
    }

}
int     main(int argc, char *argv)
{
    char    *str;

    if (argc = 2)
    {
        list
    }
    str = "moi kaikki pillinaamat.";
//    ft_putstr(str);
    list(4, 5, 2345, 2345);

    return (0);
}