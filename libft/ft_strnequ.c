/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:23:52 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:49:32 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char		*str1;
	char		*str2;
	size_t		i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (str1 && str2)
	{
		while (i < n)
		{
			if (str1[i] == '\0' && str2[i] == '\0')
				return (1);
			if (str1[i] != str2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
