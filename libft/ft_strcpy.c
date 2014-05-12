/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 00:13:25 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:09:35 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	char	*str;

	str = (char *) s1;
	while (*s2)
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = '\0';
	return (s1);
}