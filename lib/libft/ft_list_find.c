/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:22:43 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/05 14:20:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void const *content,
		size_t content_size, int (*cmp)())
{
	if (begin_list == NULL || cmp == NULL)
		return (NULL);
	while (begin_list != NULL)
	{
		if (!((*cmp)(begin_list->content, begin_list->content_size,
						content_size, content)))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
