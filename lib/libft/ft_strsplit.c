/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:57:18 by snikitin          #+#    #+#             */
/*   Updated: 2017/11/05 16:36:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**get_arr(char const *str, char c, size_t *i)
{
	char	**arr;
	int		inword;

	arr = NULL;
	inword = 0;
	while (*str)
	{
		if (*str != c && inword == 0)
		{
			inword = 1;
			(*i)++;
		}
		if (*(str + 1) == c)
			inword = 0;
		str++;
	}
	if (!(arr = (char **)malloc((*i + 1) * sizeof(char*))))
		return (NULL);
	arr[*i] = NULL;
	return (arr);
}

static size_t		ft_strsplen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static const char	*wordcopy(char const *s, char c, char **arr, size_t wordnum)
{
	size_t	wordlen;
	size_t	i;

	i = 0;
	wordlen = ft_strsplen(s, c);
	if (!(arr[wordnum] = (char *)malloc((wordlen + 1) * sizeof(char))))
	{
		while (wordnum != 0)
		{
			free(arr[wordnum]);
			wordnum--;
		}
		free(arr);
		return (NULL);
	}
	while (i < wordlen)
	{
		arr[wordnum][i] = s[i];
		i++;
	}
	arr[wordnum][i] = '\0';
	return (s + i - 1);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	wordcnt;
	char	**arr;
	size_t	wordnum;

	if (s == NULL)
		return (NULL);
	wordnum = 0;
	wordcnt = 0;
	arr = NULL;
	if (!(arr = get_arr(s, c, &wordcnt)))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			if (!(s = wordcopy(s, c, arr, wordnum)))
				return (NULL);
			wordnum++;
		}
		s++;
	}
	return (arr);
}
