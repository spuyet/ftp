/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:53:33 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:40:20 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memdel(void **ap)
{
	unsigned char	**str;

	if (ap)
	{
		str = (unsigned char **)ap;
		free((void *)*str);
		*ap = NULL;
	}
}
