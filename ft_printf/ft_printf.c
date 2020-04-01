#include "ft_printf.h"
#include <stdio.h>

void    read_flags(const char *format, t_printf *data, int place)
{

}

//make somewhere function that saves str from starting point to end point
//use ft_strsub
/**void    save_string(const char *format, t_printf *data)
{
    
}
**/
// here read the string and check for %sign.
int     start(const char *format, t_printf *data)
{
    int i;

    data->param_count = 0;
    data->str_start_point = 0;
    data->str_current_place = 0;
    i = -1;
    while(format[++i])
    (
        if (format[i] == '%')
        (
            data->new_str = ft_strsub(format, data->str_start_point, (data->str_current_place - data->str_start_point - 1))
            
            read_flags(format, data, i);
            data->param_count++;
        )
    )
    if (data->param_count == 0)
        return (0);
    return (1);
//      check the string until % comes and then send the first va_arg somewhere
//      but not if there is %% cause the other is a escape for the second one. then read it as a onw
}

int     ft_printf(const char *format, ...)
{
    t_printf    data;
    int         ret;

    i = 0;
    va_start(data.var, format);
    ret = start(format, data);
    va_arg();
    return (/**number of cahrs written **/);
}       