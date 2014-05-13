#include "ftp.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		port;

	if (ac != 2)
		s_usage(av[0]);
	else
	{
		port = ft_atoi(av[1]);
		s_run(port);
	}
	return (0);
}
