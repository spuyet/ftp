/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:17:26 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/15 17:10:54 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

char	*find_home(char *cwd)
{
	while (ft_strncmp(cwd, "ftp_home", 8))
		cwd++;
	cwd += 8;
	return (ft_strdup(cwd));
}

void	s_cd(char **tab, int cs, t_pwd *pwd)
{
	char		*data;
	char		*msg;
	char		*cwd;
	char		*tmp;

	(void)tab;
	data = NULL;
	tmp = getcwd(NULL, 0);
	if ((data = ft_recvmsg(cs, data)) == NULL)
	{
		ft_putendl("meow");
		return ;
	}
	else if (chdir(data) == -1)
		msg = "ERROR";
	else
	{
		cwd = getcwd(NULL, 0);
		if (ft_strlen(cwd) >= ft_strlen(pwd->home)
		&& !ft_strncmp(pwd->home, cwd, ft_strlen(pwd->home)))
		{
			free(pwd->serv);
			pwd->serv = find_home(cwd);
			free(cwd);
			msg = "OK";
		}
		else
		{
			chdir(tmp);
			free(tmp);
			msg = "ERROR";
		}
	}
	ft_putendl(msg);
	ft_sendmsg(cs, msg);
}
