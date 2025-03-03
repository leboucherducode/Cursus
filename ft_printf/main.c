#include "ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("%d, %d\n", 3 ,-1111);
    printf("%d, %d\n", 3 ,-1111);
    ft_printf("%x\n", -1111);
    printf("origin%x\n", -1111);
    ft_printf("%s\n", "qwerty");
    printf("%s\n", "qwerty");
    ft_printf("%p\n", (void *)NULL);
    printf("%p\n", (void *)4444);
    printf("%d, %d\n", 3 ,-1111);


    return (0);
}