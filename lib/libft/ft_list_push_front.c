/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:04:34 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/08 14:59:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void const *content,
		size_t content_size)
{
	t_list *temp;

	if (begin_list == NULL)
		return ;
	if (*begin_list == NULL)
		*begin_list = ft_lstnew(content, content_size);
	else
	{
		temp = ft_lstnew(content, content_size);
		temp->next = *begin_list;
		*begin_list = temp;
	}
}
