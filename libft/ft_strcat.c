/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:23:19 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 19:05:26 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = s1;
	ptr2 = (char *) s2;
	while (*ptr1)
		ptr1++;
	while (*ptr2)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
	}
	*ptr1 = '\0';
	return (s1);
}
