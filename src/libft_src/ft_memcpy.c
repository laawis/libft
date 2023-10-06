/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:59:24 by gaollier          #+#    #+#             */
/*   Updated: 2022/11/30 13:39:46 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*altdest;
	char	*altsrc;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	altdest = (char *)dest;
	altsrc = (char *)src;
	i = 0;
	while (i < n)
	{
			altdest[i] = altsrc[i];
			i++;
	}
	return (dest);
}
