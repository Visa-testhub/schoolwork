#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>


typedef struct  s_printf
{
    va_list     var;
    char        *new_str;
    int         param_count;
    int         chars_written;
    int         str_current_place;
    int         str_start_point;
//    char        *format;
};              t_printf


int     ft_printf(const char *format, ...);

# endif