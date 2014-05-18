#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "ftp.h"

void	c_put(char **tab, int sock)
{
	int			fd;
	struct stat	buf;
	ft_sendmsg(sock, tab[0]);
	if ((fd = open(tab[1], O_RDONLY)) == -1)
		ft_putendl("ERROR: unable to open file");
	else
	{
		ft_sendmsg(sock, tab[1]);
		if (fstat(fd, &buf) == -1)
			ft_putendl("ERROR: unable to get infos file");
		else
		{
			ft_putendl("Status: upload starded");
			ft_sendfile(sock, fd, buf.st_size);
			ft_putendl("Staus: upload finished");
		}
	}
}
