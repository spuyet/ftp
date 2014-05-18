/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:13:15 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:20:26 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"
#include "libft.h"

static t_scmds const g_funcs[] = {
	{"ls", &s_ls},
	{"pwd", &s_pwd},
	{"cd", &s_cd},
	{"get", &s_get},
	{"put", &s_put},
	{0, 0}
};

void		s_cmd(int cs, char *buf, t_pwd *pwd)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(buf, ' ');
	while (g_funcs[i].cmd)
	{
		if (ft_strcmp(g_funcs[i].cmd, tab[0]) == 0)
		{
			g_funcs[i].f(tab, cs, pwd);
			break ;
		}
		i++;
	}
	if (i == 5)
	{
		ft_putstr("Unknow command: ");
		ft_putendl(buf);
	}
	free_tab(tab);
}
