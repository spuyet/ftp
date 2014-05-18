/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:37:06 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:51:12 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str1;
	char		*str2;
	size_t		i;

	str1 = (char *)s;
	str2 = (char *)(malloc((len + 1) * sizeof(char)));
	i = 0;
	if (str1 && str2)
	{
		while (i < len)
		{
			str2[i] = str1[start];
			i++;
			start++;
		}
		str2[i] = '\0';
	}
	return (str2);
}
