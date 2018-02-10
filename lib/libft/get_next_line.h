/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:06:05 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 20:49:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 100
# define FD_SIZE 1000

# define LINE (1)
# define NOT_LINE (2)
# define ERROR (-1)

typedef struct	s_fd_strg
{
	int			fd;
	char		buff[BUFF_SIZE];
}				t_fd_strg;

int				get_next_line(const int fd, char **line);

#endif
