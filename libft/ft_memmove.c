/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:45:56 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/12 13:50:45 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_move(unsigned char *dest, unsigned char *src, size_t len)
{
	size_t		i;

	i = 0;
	if (src > dest)
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i > 0)
		{
			dest[i] = src[i];
			i--;
		}
		dest[i] = src[i];
	}
}

void		*ft_memmove(void *s1, const void *s2, size_t len)
{
	unsigned char		*dest;
	unsigned char		*src;

	dest = (unsigned char *) s1;
	src = (unsigned char *) s2;
	if (src != dest && len > 0)
		ft_move(dest, src, len);
	return ((void *) s1);
}
