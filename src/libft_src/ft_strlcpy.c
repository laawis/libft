/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:55:54 by gaollier          #+#    #+#             */
/*   Updated: 2022/11/28 12:52:44 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*src1;

	src1 = (char *)src;
	i = 0;
	while ((src1[i]) && ((i + 1) < size))
	{
		dest[i] = src1[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	len = 0;
	while (src1[len])
		len++;
	return (len);
}
