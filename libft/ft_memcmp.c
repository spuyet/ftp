/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:25:56 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 18:56:35 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
	{
		unsigned char	*str1;
		unsigned char	*str2;
		size_t			index;

		str1 = (unsigned char *) s1;
		str2 = (unsigned char *) s2;
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
