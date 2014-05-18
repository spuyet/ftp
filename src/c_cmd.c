/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:22:06 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 22:00:08 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftp.h"
#include "libft.h"

static t_cmds const	g_funcs[] =
{
	{"list", &c_list},
	{"ls", &c_ls},
	{"pwd", &c_pwd},
	{"cd", &c_cd},
	{"get", &c_get},
	{"put", &c_put},
	{0, &c_error}
};

void				c_error(char **tab, int sock)
{
	(void)sock;
	ft_putstr(tab[0]);
	ft_putendl(": Unknow command");
}

void				c_cmd(char *buf, int sock, int *run)
{
	int		i;
	int		b;
	char	**tab;

	i = 0;
	b = 0;
	if (!ft_strcmp(buf, "quit") && (*run)--)
	{
		ft_sendmsg(sock, "quit");
		exit(EXIT_SUCCESS);
	}
	tab = ft_strsplit(buf, ' ');
	while (g_funcs[i].cmd)
	{
		if (ft_strcmp(g_funcs[i].cmd, tab[0]) == 0 && ++b)
		{
			g_funcs[i].f(tab, sock);
			break ;
		}
		i++;
	}
	if (!b)
		g_funcs[i].f(tab, sock);
	free_tab(tab);
}
