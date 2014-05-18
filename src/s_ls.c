/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:24:05 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:28:44 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "ftp.h"
#include "libft.h"

void	s_ls2(t_pwd *pwd, struct dirent *dir, char **data)
{
	if (!ft_strcmp(pwd->serv, "/"))
	{
		if (ft_strcmp("..", dir->d_name))
		{
			if (**data)
				*data = ft_strfjoin(*data, "\n");
			*data = ft_strfjoin(*data, dir->d_name);
		}
	}
	else
	{
		if (*data)
			*data = ft_strfjoin(*data, "\n");
		*data = ft_strfjoin(*data, dir->d_name);
	}
}

void	s_ls(char **tab, int cs, t_pwd *pwd)
{
	DIR				*cur;
	char			*data;
	char			*tmp;
	struct dirent	*dir;

	(void)tab;
	data = ft_strnew(0);
	tmp = getcwd(NULL, 0);
	cur = opendir(tmp);
	free(tmp);
	while ((dir = readdir(cur)) != NULL)
		s_ls2(pwd, dir, &data);
	closedir(cur);
	if (!ft_sendmsg(cs, data))
		ft_putendl("unable to send message");
	free(data);
}
