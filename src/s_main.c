/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:29:47 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:31:56 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ftp.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		port;

	signal(SIGCHLD, SIG_IGN);
	if (ac != 2)
		s_usage(av[0]);
	else
	{
		port = ft_atoi(av[1]);
		s_run(port);
	}
	return (0);
}
