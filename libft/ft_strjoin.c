/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:41:13 by spuyet            #+#    #+#             */
/*   Updated: 2014/01/12 16:43:06 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char	*fill_string(char *str1, char *str2, char *str3)
{
	size_t	i;

	i = 0;
	if (str3)
	{
		while (*str1)
		{
			str3[i] = *str1;
			str1++;
			i++;
		}
		while (*str2)
		{
			str3[i] = *str2;
			str2++;
			i++;
		}
		str3[i] = '\0';
		return (str3);
	}
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*str1;
	char		*str2;
	char		*str3;
	size_t		len;

	str1 = (char *) s1;
	str2 = (char *) s2;
	if (str1 && str2)
	{
		len = ft_strlen(str1) + ft_strlen(str2) + 1;
		str3 = (char *) malloc(len * sizeof(char));
		return (fill_string(str1, str2, str3));
	}
	return (NULL);
}
