/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:38:24 by spuyet            #+#    #+#             */
/*   Updated: 2014/01/12 16:45:24 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *str1, char *str2, size_t length)
{
	char	*str3;

	str3 = NULL;
	if (str1 && str2)
	{
		str3 = ft_strnew(ft_strlen(str1) + length);
		if (str3)
		{
			ft_strcpy(str3, str1);
			ft_strncat(str3, str2, length);
		}
	}
	return (str3);
}
