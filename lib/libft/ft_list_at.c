/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:04:58 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:51:26 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
	size_t i;

	if (begin_list == NULL)
		return (NULL);
	i = 0;
	while (i != nbr && begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
