/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:22:06 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 12:48:56 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"
#include "libft.h"

static void		c_error(char **tab, int sock)
{
	(void)sock;
	ft_putstr(tab[0]);
	ft_putendl(": Unknow command");
}

void			c_cmd(char *buf, int sock)
{
	int		i;
	int		b;
	char	**tab;

	i = 0;
	b = 0;
	tab = ft_strsplit(buf, ' ');
	static t_cmds const funcs[]={
		{"list", &c_list},
		{"ls", c_ls},
		{"pwd", c_pwd},
		{"cd", c_cd},
		{0, c_error}
	};
	while (funcs[i].cmd)
	{
		if (ft_strcmp(funcs[i].cmd, tab[0]) == 0 && ++b)
		{
			funcs[i].f(tab, sock);
			break ;
		}
		i++;
	}
	if (!b)
		funcs[i].f(tab, sock);
	free_tab(tab);
}
