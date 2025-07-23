#include "libft.h"

void    *ft_realloc(void *ptr, size_t size)
{
    void    *new_ptr;

    if (!size)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = ft_calloc(1, size);
    if (ptr && new_ptr)
        ft_memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}