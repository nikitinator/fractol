/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:24:04 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/05 15:46:08 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tempo;
	t_list	*retval;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(tempo = (*f)(lst)))
		return (NULL);
	lst = lst->next;
	retval = tempo;
	while (lst)
	{
		if (!(tempo->next = (*f)(lst)))
		{
			ft_lstdel(&retval, del);
			return (NULL);
		}
		tempo = tempo->next;
		lst = lst->next;
	}
	return (retval);
}
