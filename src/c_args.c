#include "libft.h"

int		c_args(char **tab)
{
	if (tab[1] == 0)
		return (0);
	ft_putstr(tab[0]);
	ft_putendl(" doesn't take any args");
	return (1);
}
