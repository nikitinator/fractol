/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:03:36 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/04 16:06:46 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	size;
	unsigned int	ncopy;
	unsigned int	isneg;

	isneg = n < 0 ? 1 : 0;
	ncopy = n < 0 ? (unsigned int)-n : (unsigned int)n;
	size = 1;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	if (!(result = (char *)malloc(size + isneg + 1)))
		return (NULL);
	result[size + isneg] = '\0';
	result[0] = '-';
	size--;
	while (size != (unsigned int)(0 - 1))
	{
		result[size + isneg] = ncopy % 10 + '0';
		ncopy /= 10;
		size--;
	}
	return (result);
}
