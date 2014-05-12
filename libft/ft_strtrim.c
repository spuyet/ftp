/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:04:58 by spuyet            #+#    #+#             */
/*   Updated: 2014/01/12 16:44:05 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isspace(size_t c)
{
	if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

static size_t	count_spaces(char const *s)
{
	size_t	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (i);
}

static size_t	count_spaces_rev(char const *s, size_t len)
{
	if (len)
	{
		len--;
		while (ft_isspace(s[len]) && len > 0)
			len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;

	if (s)
	{
		len = count_spaces_rev(s, ft_strlen(s));
		start = count_spaces(s);
		if (!len && !start)
			return (ft_strdup(s));
		else if (start == ft_strlen(s))
			return (ft_strsub(s, 0, 0));
		else
			return (ft_strsub(s, start, len - start + 1));
	}
	return (NULL);
}
