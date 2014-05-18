/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_create.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:06:58 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 21:08:40 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "libft.h"

char	*find_host(char *host)
{
	struct hostent		*he;
	struct in_addr		**addr_list;

	if ((he = gethostbyname(host)) == NULL)
		return (0);
	addr_list = (struct in_addr **)he->h_addr_list;
	return (ft_strdup(inet_ntoa(*addr_list[0])));
}

int		c_create(char *host, int port)
{
	struct protoent		*protocol;
	struct sockaddr_in	sin;
	int					sock;
	char				*ip;

	if ((ip = find_host(host)) == NULL)
		ip = ft_strdup(host);
	if (!(protocol = getprotobyname("tcp")))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(ip);
	if ((connect(sock, (struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		ft_putendl("Unable to connect to server");
		return (-1);
	}
	return (sock);
}
