#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

#include "ftp.h"
#include "libft.h"

void		s_child(int cs)
{
	char	buf[BUFFER];
	char	*pwd;

	ft_putendl("A client is connected !");
	pwd = ft_strnew(1);
	pwd[0] = '.';
	while (1)
	{
		ft_bzero((void *)buf, BUFFER);
		recv(cs, (void *)buf, BUFFER - 1, 0);
//		ft_putstr(buf);
		if (ft_strcmp(buf, "quit") == 0)
			break ;
		else
			s_cmd(cs, buf, pwd);
	}
}
