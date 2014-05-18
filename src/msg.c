/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:31:19 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 21:55:09 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

int			ft_sendmsg(int sock, void *msg)
{
	t_header	h;

	h.size = ft_strlen(msg);
	if (send(sock, &h, sizeof(t_header), 0) < 0)
	{
		ft_putendl("unable to send header");
		return (0);
	}
	if (send(sock, msg, ft_strlen(msg), 0) < 0)
	{
		ft_putendl("unable to send message");
		return (0);
	}
	return (1);
}

void		*ft_recvmsg(int sock, void *msg)
{
	t_header	h;

	if (recv(sock, &h, sizeof(t_header), MSG_WAITALL) < 0)
	{
		ft_putendl("unable to receive header");
		return (0);
	}
	msg = ft_strnew(h.size);
	if (recv(sock, msg, h.size, MSG_WAITALL) < 1)
	{
		ft_putendl("unable to receive message");
		return (0);
	}
	return (msg);
}

int			ft_sendfile(int sock, int fd, int size)
{
	void		*buf;
	t_header	h;

	buf = malloc(size);
	read(fd, buf, size);
	h.size = size;
	if (send(sock, &h, sizeof(t_header), 0) < 0)
	{
		ft_putendl("unable to send header");
		return (0);
	}
	if (send(sock, buf, size, 0) < 0)
	{
		ft_putendl("unable to send file");
		return (0);
	}
	return (1);
}

int			ft_recvfile(int sock, char *name)
{
	void		*file;
	t_header	h;
	int			fd;

	ft_bzero(&h, sizeof(t_header));
	if (recv(sock, &h, sizeof(t_header), MSG_WAITALL) < 0)
	{
		ft_putendl("unable to receive header");
		return (0);
	}
	if ((file = ft_memalloc(h.size)) == 0)
	{
		ft_putendl("malloc failed");
		return (0);
	}
	if (recv(sock, file, h.size, MSG_WAITALL) < 0)
	{
		ft_putendl("unable to receive file");
		return (0);
	}
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, file, h.size);
	close(fd);
	free(file);
	return (1);
}
