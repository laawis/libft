#include <unistd.h>

#include "ft_printf.h"

int    print_percent(void)
{
    if (write(1, "%%", 1) <= 0)
        return (-1);
    return (1);
}
