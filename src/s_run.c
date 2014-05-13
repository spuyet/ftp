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
	ft_putendl("A client left the connection.");
	close(*cs);
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
	while (run)
	{
		cs = accept(sock, (struct sockaddr *)&client, &clen);
		s_thread(&run, sock, &cs);
		close(cs);
	}
	close(sock);
}
