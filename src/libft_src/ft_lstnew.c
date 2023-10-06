/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:12:52 by gaollier          #+#    #+#             */
/*   Updated: 2023/10/04 12:31:36 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

// Alloue avec malloc et renvoie un nouvel element. La variable membre 'content' est initialisee a l'aide
// de la valeur du parametre 'content'. La variable 'next' est initialisee a NULL.
