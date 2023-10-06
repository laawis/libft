//#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if ((*s >= *(s + start)) && (*(s + (size_t)start) < *(s + (size_t)start + len)))
		{
			*str = *s;
			str++;
			start++;
		}
		s++;
	}
	*str = '\0';
	return (str);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_substr(av[1], 3, 3));
	return (0);
}
*/
