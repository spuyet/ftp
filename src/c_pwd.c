/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:30:49 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 10:34:45 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

void	c_pwd(char **tab, int sock)
{
	char		*data;

	data = NULL;
	if (c_args(tab))
		return ;
	if (send(sock, tab[0], ft_strlen(tab[0]), 0) == -1)
	{
		ft_putstr(tab[0]);
		ft_putendl(": unable to send command");
		return ;
	}
	if ((data = ft_recvmsg(sock, data)) == NULL)
		ft_putendl("unable to receive pwd");
	ft_putendl(data);
	free(data);
}
