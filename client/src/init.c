/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:15:29 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/13 14:58:55 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <arpa/inet.h>

#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include "libft.h"
#include "ftp.h"

t_serv					*init_client(char *host, char *port)
{
	t_serv				*client;
	struct protoent		*protocol;

	if ((protocol = getprotobyname("tcp")) == 0)
		return (NULL);
	client = (t_serv *)malloc(sizeof(t_serv));
	ft_bzero(client, sizeof(t_serv));
	client->sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	client->sin.sin_family = AF_INET;
	client->sin.sin_port = htons(ft_atoi(port));
	client->sin.sin_addr.s_addr = inet_addr(host);
	if (connect(client->sock, (struct sockaddr *)&(client->sin), sizeof(client->sin)) == -1)
	{
		ft_putendl("Unable to connect to the server");
		client->run = 0;
	}
	else
		client->run = 1;
	return (client);
}
