/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:30:15 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:30:17 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	s_put(char **tab, int sock, t_pwd *pwd)
{
	char	*name;

	(void)tab;
	(void)pwd;
	name = 0;
	name = ft_recvmsg(sock, name);
	ft_recvfile(sock, name);
}
