/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:33:21 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:50:08 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	value;
	char	*str;

	value = (char)c;
	len = ft_strlen(s) - 1;
	str = (char *)s;
	if (value == '\0')
		return (str + len + 1);
	while (len >= 0)
	{
		if (str[len] == value)
			return (str + len);
		len--;
	}
	return (0);
}
