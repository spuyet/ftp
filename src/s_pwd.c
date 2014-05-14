#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftp.h"
#include "libft.h"

void	s_pwd(char **tab, int cs, char *pwd)
{
	t_header	h;
	char		*data;

	(void)tab;
	data = ft_strdup(pwd);
	data[0] = '/';
	h.size = ft_strlen(data);
	write(cs, (void *)&h, sizeof(t_header));
	if (send(cs, (void *)data, h.size, 0) == -1)
		ft_putendl("Unable to send pwd");
	free(data);
}
