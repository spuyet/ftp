/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:00:20 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:49:51 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;
	size_t		count;
	char		*str1;

	if (s1 && s1)
	{
		s2_len = ft_strlen(s2);
		str1 = (char *)s1;
		if (ft_strlen(str1) < s2_len)
			return (NULL);
		if (!s2_len)
			return (str1);
		if (s2_len > n)
			return (NULL);
		count = n - s2_len + 1;
		while (count)
		{
			if (!ft_memcmp(str1, s2, s2_len))
				return (str1);
			str1++;
			count--;
		}
	}
	return (NULL);
}
