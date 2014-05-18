/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:30:48 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:30:51 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		size_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
