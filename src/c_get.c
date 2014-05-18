#include "libft.h"
#include "ftp.h"

void	c_get(char **tab, int sock)
{
	char	*msg;

	msg = 0;
	ft_sendmsg(sock, tab[0]);
	ft_sendmsg(sock, tab[1]);
	if ((msg = ft_recvmsg(sock, msg)) == 0)
	{
		ft_putendl("ERROR: no response from server");
		return ;
	}
	if (!ft_strcmp(msg, "ERROR"))
		ft_putendl(msg);
	else
	{
		ft_putendl("Status: download started");
		if (!ft_recvfile(sock, tab[1]))
			ft_putendl("ERROR: problem during transfer");
		else
			ft_putendl("Status: download complete");
	}
}
