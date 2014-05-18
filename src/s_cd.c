/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:17:26 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/16 13:10:47 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

char		*find_home(char	*pwd)
{
	while (*pwd && ft_strncmp(pwd, HOME, ft_strlen(HOME)))
		pwd++;
	if (!*pwd)
		return (NULL);
	return (pwd + ft_strlen(HOME));
}

char		*ft_chdir(t_pwd *pwd, char *cur)
{
	char	*new;

	free(pwd->local);
	pwd->local = cur;
	new = find_home(cur);
	pwd->serv = ft_strdup(new);
	return ("OK");
}

char		*ft_cdhome(t_pwd *pwd, char *cur)
{
	free(pwd->local);
	pwd->local = cur;
	free(pwd->serv);
	pwd->serv = ft_strdup("/");
	return ("OK");
}

void		s_cd(char **tab, int cs, t_pwd *pwd)
{
	char	*data;
	char	*msg;
	char	*cur;

	(void)tab;
	data = NULL;
	if ((data = ft_recvmsg(cs, data)) == NULL)
		return ;
	if (chdir(data) == -1)
		msg = "ERROR";
	else
	{
		cur = getcwd(NULL, 0);
		if (ft_strcmp(pwd->home, cur) == 0)
			msg = ft_cdhome(pwd, cur);
		else if (ft_strlen(pwd->home) < ft_strlen(cur))
			msg = ft_chdir(pwd, cur);
		else
		{
			chdir(pwd->local);
			msg = "ERROR";
		}
	}
	free(data);
	ft_sendmsg(cs, msg);
}
