#include "ft_printf.h"
#include <stdio.h>

static int     read_flag(t_printf *data, int i)
{
    data->flags = 0;
    while (data->f[i])
    {
        if (data->f[i] == '#')
            data->flags = (data->flags | 1);
        else if (data->f[i] == '0')
            data->flags = (data->flags | 2);
        else if (data->f[i] == '-')
            data->flags = (data->flags | 4);
        else if (data->f[i] == '+')
            data->flags = (data->flags | 8);
        else if (data->f[i] == ' ')
            data->flags = (data->flags | 12);
        else
            break;
        i++;
        printf("read flag while loop end");
    }
    return (i);
}

static int      read_precision(t_printf *data, int i)
{
// ft_atoi takes string and reads it as long as there are numbers between 0 to 9 and neither not \0
    if (data->f[i] >= '0' && data->f[i] <= '9')
        data->precision = ft_atoi(data->f + i);
    while (data->f[i] >= '0' && data->f[i] <= '9')
        i++;
    return (i);
}

static int     read_conversion(t_printf *data, int i)
{
    int     a;
    char    *str;

    if (data->f[i] == 'c' || data->f[i] == 'C')
    {
        a = va_arg(data->var, int);
        write(1, &a, 1);
    }
    else if (data->f[i] == 's')
    {
        str = va_arg(data->var, char*);
        write(1, str, ft_strlen(str));
    }
    return (i);
}

static int      read_directives(t_printf *data, int i)
{
    i = read_flag(data, i);
    if (data->f[i] == '.')
        i = read_precision(data, i);
    i = read_conversion(data, i);
    return (i);
}

void             init(t_printf *data)
{
    int     i;

    data->param_count = 0;
    data->str_start_point = 0;
    data->storage = '\0';
    data->len = 0;
    i = -1;
    while(data->f[++i])
    {
        if (i == -1)
            return ; // need to do some kind of exit function. if malloc doesnt work.
        if (data->f[i] == '%' && data->f[i + 1] != '%')
        {
            // write(1, &data->f[i] , 1);
            // if (data->param_count == 0 && i != 0)
            // {
            //     if(!(data->storage = ft_strsub(data->f, data->str_start_point, ((i - 1) -
            //         data->str_start_point))))
            //         return ;
            //     if(!(ft_strncpy(data->storage, data->f,((i - 1) - data->str_start_point))))
            //         return ;
            // }
            i++;
            i = read_directives(data, i);
            // read_width(data); this is not neseccary if not for bounuses
            data->param_count++;
        }
        else if (data->f[i] == '%' && data->f[i + 1] == '%')
        {
            write(1, &data->f[i] , 1);
            i++;
        }   
        else
            write(1, &data->f[i], 1);
    }
    if (data->param_count == 0) // for knowing if there were any args
        return ;
    return ;
//      check the string until % comes and then send the first va_arg somewhere
//      but not if there is %% cause the other is a escape for the second one. then read it as a onw
}

int     ft_printf(const char *format, ...)
{
    t_printf    data;
 
    data.f = (char *)format;
    va_start(data.var, format);
    init(&data);
    // va_arg();
    va_end(data.var);
    return (0);
    // ft_strlen at the end to know the lenght of the written string so no need to return the count of chars.
}

