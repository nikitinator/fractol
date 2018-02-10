/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:49:53 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/01 16:03:07 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*contentcop;

	contentcop = NULL;
	if (!(new = (t_list *)(malloc(sizeof(t_list)))))
		return (NULL);
	if (!content)
	{
		new->content_size = 0;
		new->content = NULL;
	}
	else
	{
		new->content_size = content_size;
		if (!(contentcop = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		contentcop = ft_memmove(contentcop, content, content_size);
		new->content = contentcop;
	}
	new->next = NULL;
	return (new);
}
