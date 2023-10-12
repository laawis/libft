#include <stdlib.h>

#include "libft.h"

char *ft_strjoin_free(char *const s1, char *const s2)
{
	char *const new_s = ft_strjoin(s1, s2);

	free(s1);
	free(s2);
	return (new_s);
}
