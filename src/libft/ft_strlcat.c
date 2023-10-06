/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:18:21 by gaollier          #+#    #+#             */
/*   Updated: 2022/11/30 14:27:09 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if ((!dest || !src) && size == 0)
		return (0);
	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	while (i < size - dest_len && src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	if (i < size - dest_len)
		dest[i + dest_len] = '\0';
	else
		dest[i + dest_len - 1] = '\0';
	return (dest_len + src_len);
}
