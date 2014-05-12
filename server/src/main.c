/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:22:29 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/12 14:45:41 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"
#include "libft.h"

int		usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putstr(" <port>\n");
	return (1);
}

int		main(int ac, char **av)
{
	t_serv		*serv;

	if ((serv = init(av[1])) == NULL)
		return (1);
//	fd = accept(sock, (struct sockaddr *)&in, &inlen);
	return (0);	
}
