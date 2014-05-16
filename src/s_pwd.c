/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:29:24 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 10:33:38 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

void	s_pwd(char **tab, int cs, t_pwd *pwd)
{
	(void)tab;
	if (!ft_sendmsg(cs, pwd->serv))
		ft_putendl("unable to send message");
}
