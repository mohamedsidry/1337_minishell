#include "libft.h"

size_t ft_arrlen(char **arr)  // Changed parameter type
{
    size_t len = 0;
    
    if (!arr)
        return (0);
    while (arr[len])
        len++;
    return (len);
}