/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_run.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:30:26 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 22:02:54 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <dirent.h>
#include <netinet/in.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

static void	s_thread(int *run, int sock, int *cs)
{
	pid_t	child;

	(void)sock;
	child = fork();
	if (child != 0)
		return ;
	*run = 0;
	s_child(*cs);
	ft_putendl("A client is offline");
	close(*cs);
}

static int	s_home(void)
{
	if (opendir(HOME) == NULL)
	{
		if (mkdir(HOME, 0755) == -1)
		{
			ft_putendl("unable to create home directory.");
			return (1);
		}
	}
	if (chdir(HOME) == -1)
	{
		ft_putendl("unable to find home directory");
		return (1);
	}
	return (0);
}

void		s_run(int port)
{
	unsigned int		clen;
	struct sockaddr_in	client;
	int					sock;
	int					cs;
	int					run;

	sock = s_create(port);
	if (sock == -1)
		return ;
	run = 1;
	if (s_home())
		run = 0;
	while (run)
	{
		cs = accept(sock, (struct sockaddr *)&client, &clen);
		s_thread(&run, sock, &cs);
		close(cs);
	}
	close(sock);
}
