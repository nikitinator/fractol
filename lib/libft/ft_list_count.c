/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:59:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/29 16:18:55 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_count(t_list *begin_list)
{
	size_t	counter;

	counter = 0;
	if (begin_list == NULL)
		return (0);
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		counter++;
	}
	return (counter);
}
