#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>


typedef struct  s_printf
{
    va_list             var;
    char                *storage;
    char                *f;//format
    int                 len;
    int                 precision;
    int                 param_count;
    int                 chars_written;
    int                 str_start_point;
    unsigned short      flags;
//    char        *format;
}                       t_printf;


int     ft_printf(const char *format, ...);

# endif