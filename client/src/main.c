/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:22:29 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/13 13:23:48 by spuyet           ###   ########.fr       */
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
	ft_putstr(" <host> <port>\n");
	return (1);
}

int				main(int ac, char **av)
{
	t_serv			*serv;

	if (ac != 3 || ft_nan(av[2]))
		return (usage(av[0]));
	if ((serv = init_client(av[1], av[2])) == NULL)
		return (1);
	while (serv->run)
	{
		msg_connection(av[1], av[2]);
		serv->run = 0;
	}
	close(serv->sock);
	free(serv);
	return (0);	
}
