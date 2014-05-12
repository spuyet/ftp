/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 23:56:53 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:15:11 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*src;
	char		*dst;
	size_t		i;

	src = (char *) s;
	if (src && f)
	{
		dst = ft_strnew(ft_strlen(s));
		i = 0;
		while (src[i] != '\0')
		{
			dst[i] = (*f)(src[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
