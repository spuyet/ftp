#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include "ftp.h"

int		s_create(int port)
{
	struct protoent		*protocol;
	struct sockaddr_in	sin;
	int					sock;

	if (!(protocol = getprotobyname("tcp")))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(sock, (struct sockaddr *)&sin, sizeof(sin))) == -1)
		return (-1);
	if (listen(sock, 42) == -1)
		return (-1);
	return (sock);
}
