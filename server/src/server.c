/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:11:06 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/13 13:26:19 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ftp.h"

static int			init_connection(t_serv **data, t_serv *serv)
{
	if ((*data = init_data()) == NULL)
	{
		ft_putendl("No port available for connection. C closed");
		return (0);
	}
	else
	{
		if (send(serv->cs, (void *)*data, sizeof(t_serv), 0) < 1)
		{
			ft_putendl("Unable to send DTPM. Connection closed");
			return (0);
		}
	}
	return (1);
}

void		run_server(t_serv *serv)
{
	pid_t	cmd;
	int		connect;
	char	buf[1024];
	t_serv	*data;

	cmd = fork();
	if (cmd != 0)
		return ;
	connect = init_connection(&data, serv);
	serv->run = 0;
	while (connect)
	{
			
		ft_bzero((void *)buf, 1024);
		recv(data->cs, (void *)buf, 1023, 0); 
		ft_putstr("Commande recu : ");
		ft_putstr(buf);
		connect = 0;
		if (ft_strncmp("quit", buf, 4) == 0)
		{
			ft_putstr("exit");
			break ;
		}
	}
	close(data->cs);
	close(data->sock);
}
