#include <sys/socket.h>
#include <unistd.h>

#include "ftp.h"
#include "libft.h"

void		s_child(int cs)
{
	int		run;
	char	buf[BUFFER];

	run = 1;
	ft_putendl("A client is connected !");
	while (run)
	{
		ft_bzero((void *)buf, BUFFER);
		recv(cs, (void *)buf, BUFFER - 1, 0);
		ft_putstr(buf);
		if (ft_strcmp(buf, "quit") == 0)
			run = 0;
	}
}
