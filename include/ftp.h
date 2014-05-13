#ifndef FTP_H
# define FTP_H

# define BUFFER		1024

/*
** c_create.c
*/

int		c_create(char *host, int port);

/*
** c_run.c
*/

void	c_run(char *host, int port);

/*
** c_usage.c
*/

void	c_usage(char *name);

/*
** s_child.c
*/

void	s_child(int cs);

/*
** s_create.c
*/

int		s_create(int port);

/*
** s_run
*/

void	s_run(int port);

/*
** s_usage.c
*/

void	s_usage(char *name);

#endif
