/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:12:53 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:41:34 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	convert;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	convert = (unsigned char)c;
	while (i < len)
	{
		str[i] = convert;
		i++;
	}
	return (b);
}
