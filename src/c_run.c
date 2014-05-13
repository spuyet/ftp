#include <unistd.h>
#include <stdlib.h>
#include "ftp.h"
#include "libft.h"

void		c_run(char *host, int port)
{
	int		n;
	int		sock;
	int		run;
	char	*buf;

	sock = c_create(host, port);
	if (sock == -1)
		return ;
	run = 1;
	while (run)
	{
		if ((n = get_next_line(0, &buf)) < 1)
			break ;
		write(sock, buf, BUFFER);
		if (ft_strcmp(buf, "quit") == 0)
			run = 0;
		free(buf);
	}
}
