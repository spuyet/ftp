/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:35:34 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:39:51 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*src;
	unsigned char		*dst;

	src = (unsigned char *)s2;
	dst = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return ((void *)dst);
}
