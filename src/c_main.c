/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:08:19 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 21:25:54 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		port;

	if (ac != 3)
		c_usage(av[0]);
	else
	{
		port = ft_atoi(av[2]);
		c_run(av[1], port);
		ft_putendl("Connection is shutting down.");
	}
	return (0);
}
