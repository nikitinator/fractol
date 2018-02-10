/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:44:05 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/05 14:10:40 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst == NULL || del == NULL)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		ft_lstdelone(alst, (*del));
		*alst = temp;
	}
}
