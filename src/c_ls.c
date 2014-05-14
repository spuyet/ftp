#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

void	c_ls(char **tab, int sock)
{
	int			n;
	char		*data;
	t_header	h;

	if (c_args(tab))
		return ;
	if (send(sock, tab[0], ft_strlen(tab[0]), 0) == -1)
	{
		ft_putstr(tab[0]);
		ft_putendl(": unable to send command");
		return ;
	}
	bzero((void *)&h, sizeof(t_header));
	read(sock, (void *)&h, sizeof(t_header));
	data = ft_strnew(h.size);
	if ((n = recv(sock, data, h.size, 0)) < 1)
	{
		ft_putstr(tab[0]);
		ft_putendl(": no response from server");
		return ;
	}
	ft_putendl(data);
	free(data);
}
