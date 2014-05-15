#include <sys/socket.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

void	s_pwd(char **tab, int cs, t_pwd *pwd)
{
	t_header	h;

	(void)tab;
	h.size = ft_strlen(pwd->serv);
	write(cs, (void *)&h, sizeof(t_header));
	if (send(cs, (void *)pwd->serv, h.size, 0) == -1)
		ft_putendl("Unable to send pwd");
}
