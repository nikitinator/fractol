/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:04:31 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 20:42:40 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				get_strg_index(int fd, t_fd_strg *strg)
{
	size_t	i;

	fd += 1;
	i = 0;
	while (strg[i].fd > 0)
	{
		if (strg[i].fd == fd)
			return (i);
		i++;
	}
	i = 0;
	while (strg[i].fd > 0)
		i++;
	strg[i].fd = fd;
	return (i);
}

static int				copy_to_lnbreak(char **dst, char *src)
{
	size_t	i;
	char	*to_free;

	i = 0;
	to_free = *dst;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
	{
		src[i] = '\0';
		i++;
		*dst = ft_strjoin(*dst, src);
		free(to_free);
		ft_strcpy(src, src + i);
		return (LINE);
	}
	else if (src[i] == '\0')
	{
		*dst = ft_strjoin(*dst, src);
		free(to_free);
		ft_strclr(src);
		return (NOT_LINE);
	}
	return (ERROR);
}

int						get_next_line(const int fd, char **line)
{
	int					n_bytes_read;
	int					index;
	char				buf[BUFF_SIZE + 1];
	static t_fd_strg	storage[FD_SIZE];

	if (fd < 0 || !line || FD_SIZE <= 0 || !(*line = ft_strnew(0)))
		return (ERROR);
	ft_bzero(buf, BUFF_SIZE + 1);
	index = get_strg_index(fd, storage);
	if (copy_to_lnbreak(line, storage[index].buff) == LINE)
		return (LINE);
	while ((n_bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((copy_to_lnbreak(line, buf) == LINE))
		{
			ft_strcpy(storage[index].buff, buf);
			return (LINE);
		}
	}
	if (**line)
		return (LINE);
	free(*line);
	storage[index].fd = -1;
	return (n_bytes_read);
}
