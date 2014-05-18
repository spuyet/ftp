/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:41:13 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:47:33 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char	*fill_string(char *str1, char *str2, char *str3, char *str)
{
	size_t	i;

	i = 0;
	while (*str1)
	{
		str[i] = *str1;
		str1++;
		i++;
	}
	while (*str2)
	{
		str[i] = *str2;
		str2++;
		i++;
	}
	while (*str3)
	{
		str[i] = *str3;
		str3++;
		i++;
	}
	return (str);
}

char		*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*str;
	size_t	len;

	if (s1 && s2 && s3)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
		str = (char *)malloc(len * sizeof(char));
		if (str)
		{
			str[len - 1] = '\0';
			return (fill_string(s1, s2, s3, str));
		}
	}
	return (NULL);
}
