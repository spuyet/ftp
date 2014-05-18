/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:07:59 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:08:01 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
