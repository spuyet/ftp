/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:14:11 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 21:54:06 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

static void		sget2(int fd, int cs, struct stat *buf)
{
	if (fstat(fd, buf) == -1)
		ft_sendmsg(cs, "ERROR");
	else
	{
		ft_sendmsg(cs, "OK");
		ft_sendfile(cs, fd, buf->st_size);
	}
	close(fd);
}

void			s_get(char **tab, int cs, t_pwd *pwd)
{
	char		*name;
	int			fd;
	struct stat	buf;

	(void)tab;
	(void)pwd;
	name = 0;
	if ((name = ft_recvmsg(cs, name)) == 0)
		ft_putendl("unable to receive file name");
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_sendmsg(cs, "ERROR");
	else
		sget2(fd, cs, &buf);
}
