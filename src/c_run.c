/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_run.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:32:56 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 22:11:27 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "ftp.h"
#include "libft.h"

int			ft_space(char *s)
{
	while (*s)
	{
		if (*s != 32)
			return (0);
		s++;
	}
	return (1);
}

void		c_run(char *host, int port)
{
	int		n;
	int		sock;
	int		run;
	char	*buf;

	sock = c_create(host, port);
	if (sock == -1)
		return ;
	run = 1;
	ft_putendl("Welcome to ft_p v0.1");
	while (run)
	{
		ft_putstr("$ > ");
		if ((n = get_next_line(0, &buf)) < 1)
			break ;
		if (!buf || !*buf || ft_space(buf))
			;
		else
			c_cmd(buf, sock, &run);
		if (buf)
			free(buf);
	}
	close(sock);
}
