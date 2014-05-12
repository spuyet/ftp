/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:26:20 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:16:35 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(s1);
	if (s1 && s2)
	{
		while (s2[i] && i < n)
		{
			s1[len + i] = s2[i];
			i++;
		}
		s1[len + i] = '\0';
	}
	return (s1);
}
