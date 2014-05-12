/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:53:00 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:09:02 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	*str;

	index = 0;
	str = (char *) s;
	if (s)
	{
		while (s[index] != '\0')
		{
			if (s[index] == c)
				return (str + index);
			index++;
		}
		if (c == 0)
			return (str + index);
	}
	return (NULL);
}
