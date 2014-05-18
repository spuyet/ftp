/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:58:31 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 18:58:35 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		c_args(char **tab)
{
	if (tab[1] == 0)
		return (0);
	ft_putstr(tab[0]);
	ft_putendl(" doesn't take any args");
	return (1);
}
