/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_child.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:32:20 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 13:07:11 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftp.h"
#include "libft.h"

extern char		**environ;

static	char	*getpwd(void)
{
	char	*pwd;
	char	*tmp;
	int		i;

	i = 0;
	if (environ == NULL)
		return (NULL);
	while (environ[i])
	{
		if (!ft_strncmp("PWD=", environ[i], 4))
		{
			tmp = ft_strsub(environ[i], 4, ft_strlen(environ[i]) - 4);
			pwd = ft_strjoin3(tmp, "/", HOME);
			free(tmp);
			return (pwd);
		}
		i++;
	}
	return (NULL);
}

static t_pwd	*init_pwd(void)
{
	t_pwd	*pwd;

	pwd = (t_pwd *)malloc(sizeof(t_pwd));
	pwd->serv = ft_strdup("/");
	pwd->local = getpwd();
	pwd->home = ft_strdup(pwd->local);
	if (pwd->local == NULL || !*(pwd->local))
		return (NULL);
	return (pwd);
}

void			s_child(int cs)
{
	t_pwd	*pwd;
	char	*buf;

	buf = NULL;
	pwd = init_pwd();
	if (pwd == NULL)
	{
		ft_putendl("Wrong pwd. program stop");
		return ;
	}
	while (1)
	{
		if ((buf = ft_recvmsg(cs, buf)) == NULL)
			break ;
		if (ft_strcmp(buf, "quit") == 0)
			break ;
		else
			s_cmd(cs, buf, pwd);
	}
}
