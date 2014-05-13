/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:22:29 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/13 11:34:18 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftp.h"
#include "libft.h"

static int		usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putstr(" <port>\n");
	return (1);
}

int				main(int ac, char **av)
{
	t_serv			*serv;

	if (ac != 2 || ft_nan(av[1]))
		return (usage(av[0]));
	if ((serv = init(av[1])) == NULL)
		return (1);
	while (serv->run)
	{
		serv->cs = accept(serv->sock, (struct sockaddr *)&(serv->csin), &(serv->cslen));
		ft_putendl("Un client s'est connecte");
		run_server(serv);	
	}
	close(serv->cs);
	close(serv->sock);
	free(serv);
	return (0);	
}
