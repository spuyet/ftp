/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:11:06 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/12 18:25:23 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftp.h"

void		run_server(t_serv *serv)
{
	char	buf[1024];
	int		r;

	ft_bzero((void *)buf, 1024);
	ft_putendl("Dessine moi un mouton !");
	while ((r = read(serv->cs, buf, 1023)) > 0)
	{
		buf[r] = 0;
		ft_putstr("ton message est: [");
		ft_putstr(buf);
		ft_putstr("]\n");
	}
	ft_putendl("exit");
	exit(0);
}
