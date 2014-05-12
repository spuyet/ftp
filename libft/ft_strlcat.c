/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:14:51 by spuyet            #+#    #+#             */
/*   Updated: 2014/01/03 08:28:02 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			return (i);
		i++;
	}
	return (size);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	i;
	size_t	ret;

	i = 0;
	if (size <= (ft_strnlen(dst, size) + 1))
			return (ft_strnlen(dst, size) + ft_strlen(src));
	n = ft_strlen(dst);
	ret = n + ft_strlen(src);
	while (src[i] != '\0')
	{
		if (n < size - 1)
		{
			dst[n] = src[i];
			n++;
		}
		i++;
	}
	dst[n] = '\0';
	return (ret);
}
