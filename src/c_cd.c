#include <sys/socket.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

static void		c_cderr(char *str)
{
	ft_putstr(str);
	ft_putendl(": not enough or too many arguments");
}

static void		c_cd2(char **tab, int sock)
{
	char		*data;

	data = NULL;
	if (send(sock, tab[0], ft_strlen(tab[0]), 0) == -1)
	{
		ft_putstr(tab[0]);
		ft_putendl(": unable to send command");
		return ;
	}
	ft_putendl("cmd send");
	if (!ft_sendmsg(sock, tab[1]))
		return ;
	ft_putendl("msg send");
	if ((data = ft_recvmsg(sock, data)) == NULL)
		return ;
	ft_putendl("reponse recu");
	ft_putstr(tab[0]);
	ft_putstr(": ");
	ft_putendl(data);
}

void			c_cd(char **tab, int sock)
{
	int		size;

	size = size_tab(tab);
	if (size == 2)
		c_cd2(tab, sock);
	else
		c_cderr(tab[0]);
}
