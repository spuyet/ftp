#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "libft.h"

int		c_create(char *host, int port)
{
	struct protoent		*protocol;
	struct sockaddr_in	sin;
	int					sock;

	if (!(protocol = getprotobyname("tcp")))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(host);
	if ((connect(sock, (struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		ft_putendl("Unable to connect to server");
		return (-1);
	}
	return (sock);
}
