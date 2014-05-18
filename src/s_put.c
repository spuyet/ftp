#include "ftp.h"

void	s_put(char **tab, int sock, t_pwd *pwd)
{
	char	*name;

	(void)tab;
	(void)pwd;
	name = 0;
	name = ft_recvmsg(sock, name);
	ft_recvfile(sock, name);
}
