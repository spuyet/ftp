/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:15:29 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/12 15:02:24 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include "ftp.h"

t_serv					*init(char *str)
{
	t_serv				*serv;
	struct protoent		*protocol;

	if ((protocol = getprotobyname("tcp")) == 0)
		return (NULL);
	serv = (t_serv *)malloc(sizeof(t_serv));
	serv->sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	serv->sin.sin_family = AF_INET;
	serv->cs.sin_addr.s_addr = htonl(INADDR_ANY);
//	if (bind(serv->sock, (struct sockaddr *)&(serv->sin), sizeof(serv->sin)) == -1)
//		return (NULL);
	listen(serv->sock, 42);
	return (serv);
}
