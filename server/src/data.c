/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 09:42:58 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/13 11:26:19 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ftp.h"

t_serv			*init_data()
{
	t_serv		*data;
	char		*str;
	int			port;

	port = 1025;
	str = ft_itoa(port);
	while ((data = init(str)) == NULL)
	{
		if (port > 1050)
			break ;
		free(str);
		port++;
		str = ft_itoa(port);
	}
	free(str);
	return (data);
}
