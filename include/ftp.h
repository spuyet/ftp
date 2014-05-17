/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 16:16:52 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/15 16:16:54 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# define HOME		"ftp_home"
# define BUFFER		1024

typedef struct	s_cmds
{
	char		*cmd;
	void		(*f)(char **, int);
}				t_cmds;

typedef struct s_pwd
{
	char		*local;
	char		*serv;
	char		*home;
}				t_pwd;

typedef struct	s_scmds
{
	char		*cmd;
	void		(*f)(char **, int, t_pwd *);
}				t_scmds;

typedef struct	s_header
{
	char		*name;
	int			size;
}				t_header;

/*
** c_args.c
*/
int		c_args(char **tab);

/*
** c_cd.c
*/

void	c_cd(char **tab, int sock);

/*
** c_cmd.c
*/

void	c_cmd(char *buf, int sock, int *run);

/*
** c_create.c
*/

int		c_create(char *host, int port);

/*
** c_list.c
*/

void	c_list(char **tab, int sock);

/*
** c_ls.c
*/

void	c_ls(char **tab, int sock);

/*
** c_pwd.c
*/

void	c_pwd(char **tab, int sock);

/*
** c_run.c
*/

void	c_run(char *host, int port);

/*
** c_usage.c
*/

void	c_usage(char *name);

/*
** msg.c
*/

char	*ft_recvmsg(int sock, char *msg);
int		ft_sendmsg(int sock, char *msg);

/*
** s_cd.c
*/

void	s_cd(char **tab, int cs, t_pwd *pwd);

/*
** s_child.c
*/

void	s_child(int cs);

/*
** s_cmd.c
*/

void	s_cmd(int cs, char *buf, t_pwd *pwd);

/*
** s_create.c
*/

int		s_create(int port);


/*
** s_ls.c
*/

void	s_ls(char **tab, int cs, t_pwd *pwd);

/*
** s_pwd.c
*/

void	s_pwd(char **tab, int cs, t_pwd *pwd);

/*
** s_run
*/

void	s_run(int port);

/*
** s_usage.c
*/

void	s_usage(char *name);

/*
** utils.c
*/

void	free_tab(char **tab);
int		size_tab(char **tab);

#endif
