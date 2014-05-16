/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:31:19 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 10:38:02 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

int			ft_sendmsg(int sock, char *msg)
{
	t_header	h;

	h.size = ft_strlen(msg);
	if (send(sock, (void *)&h, sizeof(t_header), 0) < 0)
	{
		ft_putendl("unable to send header");
		return (0);
	}
	if (send(sock, (void *)msg, ft_strlen(msg), 0) < 0)
	{
		ft_putendl("unable to send message");
		return (0);
	}
	return (1);
}

char		*ft_recvmsg(int sock, char *msg)
{
	t_header	h;

	if (recv(sock, (void *)&h, sizeof(t_header), MSG_WAITALL) <  0)
	{
		ft_putendl("unable to receive header");
		return (0);
	}
	msg = ft_strnew(h.size);
	if (recv(sock, (void *)msg, h.size, MSG_WAITALL) <  1)
	{
		ft_putendl("unable to receive message");
		return (0);
	}
	return (msg);
}