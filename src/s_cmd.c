#include "ftp.h"
#include "libft.h"

void		s_cmd(int cs, char *buf, char *pwd)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(buf, ' ');
	static t_scmds const funcs[] = {
		{"ls", &s_ls},
		{"pwd", &s_pwd},
		{0, 0}
	};
	while (funcs[i].cmd)
	{
		if (ft_strcmp(funcs[i].cmd, tab[0]) == 0)
			funcs[i].f(tab, cs, pwd);
		i++;
	}
	free_tab(tab);
}
