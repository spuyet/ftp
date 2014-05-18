/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:53:33 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/18 19:37:49 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)malloc(size);
	if (ptr)
	{
		while (i < size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return ((void *)ptr);
}
