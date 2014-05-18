/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:57:09 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:49:01 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char			*str1;
	char			*str2;
	size_t			i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i - 1] - str2[i - 1]);
}
