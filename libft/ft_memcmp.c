/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:25:56 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:42:54 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	if (n)
	{
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		index = 0;
		while (index < n)
		{
			if (str1[index] != str2[index])
				return (str1[index] - str2[index]);
			index++;
		}
	}
	return (0);
}
