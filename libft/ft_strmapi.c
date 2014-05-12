/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 23:57:23 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:15:31 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			dst[i] = (*f)(i, src[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
