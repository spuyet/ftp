/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_child.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:32:20 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 22:01:06 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

static t_pwd	*init_pwd(void)
{
	t_pwd	*pwd;

	pwd = (t_pwd *)malloc(sizeof(t_pwd));
	pwd->serv = ft_strdup("/");
	pwd->local = getcwd(NULL, 0);
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
	ft_putendl("A client is online.");
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
