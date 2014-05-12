/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:13:04 by spuyet            #+#    #+#             */
/*   Updated: 2014/01/12 16:42:19 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fill_string(char *str, int n, int flag, int size)
{
	while (n != 0)
	{
		str[size] = n % 10 + '0';
		if (flag > 1)
		{
			str[size] = str[size] + 1;
			flag--;
		}
		n = n / 10;
		size--;
	}
	return (size);
}

static char	*number_zero(void)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = '0';
	return (str);
}

static int	count_digits(int n, int size)
{
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	int		flag;
	char	*str;

	flag = 0;
	size = (n == 0) ? 1 : 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			flag++;
			n = n + 1;
		}
		n = -n;
		size++;
		flag++;
	}
	size = count_digits(n, size);
	str = ft_strnew(size);
	size--;
	if (n == 0)
		return (number_zero());
	size = fill_string(str, n, flag, size);
	str[0] = (flag > 0) ? '-' : str[0];
	return (str);
}
