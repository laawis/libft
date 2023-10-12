#include <unistd.h>
#include <libft.h>

#include "ft_printf.h"

int print_str(char *str)
{
    if (str == NULL)
    {
        return (-1);
    }
	return (write(1, str, ft_strlen(str)));
}

