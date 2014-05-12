/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <spuyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:23:10 by spuyet            #+#    #+#             */
/*   Updated: 2014/05/12 17:33:26 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# define QUEUE	10

# include <netinet/in.h>

typedef struct			s_serv
{
	int					sock;
	int					cs;
	int					run;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	struct sockaddr_in	sin;
}						t_serv;


/*
** init.c
*/

t_serv					*init(char *str);

/*
** nan.c
*/

int						ft_nan(char *str);

/*
** server.c
*/

void					run_server(t_serv *serv);

#endif
