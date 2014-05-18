#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

void	s_get(char **tab, int cs, t_pwd *pwd)
{
	char		*name;
	int			fd;
	struct stat	buf;

	name = 0;
	(void)tab;
	(void)pwd;
	ft_putendl("waiting filename");
	if ((name = ft_recvmsg(cs, name)) == 0)
		ft_putendl("unable to receive file name");
	ft_putendl("opening file");
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_sendmsg(cs, "ERROR");
	else
	{
		ft_putendl("file open");
		if (fstat(fd, &buf) == -1)
		{
			ft_sendmsg(cs, "ERROR");
			ft_putendl("unable to stat file");
		}
		else
		{
			ft_putendl("stat file ok");
			ft_sendmsg(cs, "OK");
			ft_putendl("sending file");
			ft_sendfile(cs, fd, buf.st_size);
		}
		close(fd);
	}
}
