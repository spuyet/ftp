/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 23:50:39 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:10:57 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t		i;
	char		*str1;
	char		*str2;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	if (str1 && str2)
	{
		while (str1[i] != '\0' && str2[i] != '\0')
		{
			if (str1[i] != str2[i])
				return (0);
			i++;
		}
		if (str1[i] != str2[i])
			return (0);
		return (1);
	}
	return (0);
}
