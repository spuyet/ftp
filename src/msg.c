#include <stdio.h>

#include <sys/socket.h>
#include <unistd.h>
#include "libft.h"
#include "ftp.h"

int			ft_sendmsg(int sock, char *msg)
{
	t_header	h;

	ft_bzero((void *)&h, sizeof(t_header));
	h.size = ft_strlen(msg);
	printf("envoi du header de taille %d\n", h.size);
/*	if (send(sock, (void *)&h, sizeof(t_header), 0) == -1)
	{
		ft_putendl("unable to send header");
		return (0);
	}
*/
	write(sock, (void *)&h, sizeof(t_header));
	printf("header envoye\n");
	if (send(sock, (void *)msg, ft_strlen(msg), 0) == -1)
	{
		ft_putendl("unable to send message");
		return (0);
	}
	printf("le message [%s] de taille %d est envoye\n", msg, h.size);
	return (1);
}

char		*ft_recvmsg(int sock, char *msg)
{
	t_header	h;

	ft_bzero((void *)&h, sizeof(t_header));

	printf("attente reception header\n");
	read(sock, (void *)&h, sizeof(t_header));
	printf("header recu, le message fera %d octets\n", h.size);
/*	if (recv(sock, (void *)&h, sizeof(t_header), 0) <  0)
	{
		ft_putendl("unable to receive header");
		return (0);
	}
*/
	msg = ft_strnew(h.size);
	printf("%p = addr string alloue\n", msg);
	printf("chaine allouee\nattente reception message");
	if (recv(sock, (void *)msg, h.size, 0) <  1)
	{
		ft_putendl("unable to receive message");
		return (0);
	}
	printf("message recu [%s]\n", msg);
	return (msg);
}
