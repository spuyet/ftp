#include "ftp.h"
#include "libft.h"

void		s_cmd(int cs, char *buf, t_pwd *pwd)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(buf, ' ');
	static t_scmds const funcs[] = {
		{"ls", &s_ls},
		{"pwd", &s_pwd},
		{"cd", &s_cd},
		{"get", &s_get},
		{"put", &s_put},
		{0, 0}
	};
	while (funcs[i].cmd)
	{
		if (ft_strcmp(funcs[i].cmd, tab[0]) == 0)
		{
			funcs[i].f(tab, cs, pwd);
			break ;
		}
		i++;
	}
	if (i == 5)
	{
		ft_putstr("Unknow command: ");
		ft_putendl(buf);
	}
	free_tab(tab);
}
