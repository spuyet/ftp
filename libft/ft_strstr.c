/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:40:07 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:38:00 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		count;
	char		*str1;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str1 = (char *) s1;
	if (s1_len < s2_len)
		return (NULL);
	if (!s2_len)
		return (str1);
	count = s1_len - s2_len + 1;
	while (count)
	{
		if (!ft_memcmp(str1, s2, s2_len))
			return (str1);
		str1++;
		count--;
	}
	return (NULL);
}
