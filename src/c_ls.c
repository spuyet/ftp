/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:16:24 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 10:28:11 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

void	c_ls(char **tab, int sock)
{
	char		*data;

	data = NULL;
	if (c_args(tab))
		return ;
	if (!ft_sendmsg(sock, tab[0]))
		ft_putendl("unable to send cmd");
	data = ft_recvmsg(sock, data);
	if (data == NULL)
		ft_putendl("unable to receive message");
	else
	{
		ft_putendl(data);
		free(data);
	}
}
