#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

// int     main(void)
// {
//     float f = 4.132413;
//     char *words = "Moikka Maika ja Noel";

//     printf("%.2f \n%s\n", f, words);
//     printf("now the test \n\n");
//     printf ("Characters: %c %c \n", 'a', 65);
//     printf ("Decimals: %d %ld\n", 1977, 650000L);
//     printf ("Preceding with blanks: %10d \n", 1977);
//     printf ("Preceding with zeros : %010d \n", 1977);
//     printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
//     printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
//     printf ("Width trick: %*d \n", 5, 10);
//     printf ("%s \n", "A string");
//     printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "no terve", "moromoro osta poro");
//     return (0);
// }

int     main(void)
{
    // char one = '1';
    char    *str;
    int     nb = 5050505;

    itoa(nb, str, 10);
    printf("%s", str);
    // ft_printf("my name is %s\n", str);
    return (0);
}