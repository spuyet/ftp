/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 13:20:46 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/13 13:23:39 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	msg_connection(char *host, char *port)
{
	ft_putstr("Connection established on ");
	ft_putstr(host);
	ft_putstr(" with port ");
	ft_putendl(port);
}
