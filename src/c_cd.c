/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:17:12 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 13:11:54 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

static void		c_cderr(char *str)
{
	ft_putstr(str);
	ft_putendl(": not enough or too many arguments");
}

static void		c_cd2(char **tab, int sock)
{
	char		*data;

	data = NULL;
	(void)data;
	if (!ft_sendmsg(sock, tab[0]))
		return ;
	if (!ft_sendmsg(sock, tab[1]))
		return ;
	if ((data = ft_recvmsg(sock, data)) == NULL)
		return ;
	ft_putstr(tab[0]);
	ft_putstr(": ");
	ft_putendl(data);
}

void			c_cd(char **tab, int sock)
{
	int		size;
	int		i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
	size = size_tab(tab);
	if (size == 2)
		c_cd2(tab, sock);
	else
		c_cderr(tab[0]);
}
