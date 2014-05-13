#include "ftp.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		port;

	if (ac != 3)
		c_usage(av[0]);
	else
	{
		port = ft_atoi(av[2]);
		c_run(av[1], port);
		ft_putendl("connection is shutting down.");
	}
	return (0);
}
