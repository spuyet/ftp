/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_run.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:32:56 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 10:37:19 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftp.h"
#include "libft.h"

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
	ft_putendl("Welcome to f_tp v0.1");
	while (run)
	{
		ft_putstr("$ > ");
		if ((n = get_next_line(0, &buf)) < 1)
			break ;
		else if (!n)
			;
		else if (ft_strcmp(buf, "quit") == 0)
			run = 0;
		else
			c_cmd(buf, sock);
	//	write(sock, buf, BUFFER);
		free(buf);
	}
	close(sock);
}
