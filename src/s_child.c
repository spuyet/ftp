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

#include <stdio.h>

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
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
	printf("%s\n", pwd->serv);
	printf("%s\n", pwd->local);
	printf("%s\n", pwd->home);
	if (pwd->local == NULL || !*(pwd->local))
		return (NULL);
	return (pwd);
}

void			s_child(int cs)
{
	char	buf[BUFFER];
	t_pwd	*pwd;

	pwd = init_pwd();
	if (pwd == NULL)
	{
		ft_putendl("wrong pwd. program stop");
		return ;
	}
	ft_putendl("A client is connected !");
	while (1)
	{
		ft_bzero((void *)buf, BUFFER);
		recv(cs, (void *)buf, BUFFER - 1, 0);
		if (ft_strcmp(buf, "quit") == 0)
			break ;
		else
			s_cmd(cs, buf, pwd);
	}
}
