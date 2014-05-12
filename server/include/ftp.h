/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:23:10 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/12 15:02:26 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

#include <netinet/in.h>

typedef struct			s_serv
{
	int					sock;
	struct sockaddr_in	sin;
	struct sockaddr_in	cs;
	unsigned int		cslen;
}						t_serv;

t_serv					*init(char *str);

#endif
