#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "ftp.h"
#include "libft.h"

void	s_ls(char **tab, int cs, char *pwd)
{
	DIR				*cur;
	char			*data;
	struct dirent	*dir;
	t_header		h;

	(void)tab;
	data = ft_strnew(0);
	cur = opendir(pwd);
	while ((dir = readdir(cur)) != NULL)
	{
		if (ft_strcmp(".", dir->d_name) && ft_strcmp("..", dir->d_name))
		{
			if (*data)
				data = ft_strfjoin(data, "\n");
			data = ft_strfjoin(data, dir->d_name);
		}
	}
	closedir(cur);
	h.size = ft_strlen(data);
	write(cs, (void *)&h, sizeof(t_header));
	if (send(cs, (void *)data, h.size, 0) == -1)
		ft_putendl("Unable to send data");
	free(data);
}
