/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:25:16 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/16 17:03:12 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi_base(char *str, int base)
{
	int					i;
	int					sign;
	char				*sym;
	unsigned long int	result;

	sym = "0123456789ABCDEF";
	result = 0;
	sign = 1;
	while (ft_iswhsp(*str))
		str++;
	i = -1;
	while (str[i++])
		str[i] = ft_toupper(str[i]);
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F'))
	{
		result = (result * base) + (int)(ft_strchr(sym, *str) - sym);
		str++;
	}
	return ((int)(result * (unsigned long)sign));
}
