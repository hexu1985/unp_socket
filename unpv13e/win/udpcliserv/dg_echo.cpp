#include "dg_echo.hpp"
#include "config.hpp"
#include "err_quit.hpp"

void
dg_echo(SOCKET sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{
	int			n;
	socklen_t	len;
	char		mesg[MAXLINE];

	for ( ; ; ) {
		len = clilen;
		n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
		if (n == SOCKET_ERROR)
			err_quit("recvfrom error");

		if (sendto(sockfd, mesg, n, 0, pcliaddr, len) == SOCKET_ERROR)
			err_quit("sendto error");
	}
}
