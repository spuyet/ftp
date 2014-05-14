#include "libft.h"

void	c_list(char **tab, int sock)
{
	(void)tab;
	(void)sock;
	ft_putchar('\n');
	ft_putendl("ls -> list file on the ftp server");
	ft_putendl("cd <DIR> -> change current directory");
	ft_putendl("get <FILE> -> download file from server");
	ft_putendl("put <FILE> -> upload file to server");
	ft_putendl("pwd -> print the current directory path");
	ft_putendl("quit -> close the ftp client");
	ft_putchar('\n');
}
