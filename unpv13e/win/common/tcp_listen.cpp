/* include tcp_listen */
#include "tcp_listen.hpp"

#include <string.h>

#include "err_quit.hpp"
#include "config.hpp"

SOCKET
tcp_listen(const char *host, const char *serv, socklen_t *addrlenp)
{
	SOCKET			listenfd;
    int             n;
	const int		on = 1;
	struct addrinfo	hints, *res, *ressave;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
		err_quit("tcp_listen error for %s, %s: %s",
				 host, serv, gai_strerror(n));
	ressave = res;

	do {
		listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (listenfd == INVALID_SOCKET)
			continue;		/* error, try next one */

		if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on)) == SOCKET_ERROR)
			err_quit("setsockopt error");
		if (bind(listenfd, res->ai_addr, res->ai_addrlen) == 0)
			break;			/* success */

		closesocket(listenfd);	/* bind error, close and try next one */
	} while ( (res = res->ai_next) != NULL);

	if (res == NULL)	/* errno from final socket() or bind() */
		err_quit("tcp_listen error for %s, %s", host, serv);

	if (listen(listenfd, LISTENQ) == SOCKET_ERROR)
		err_quit("listen error");

	if (addrlenp)
		*addrlenp = res->ai_addrlen;	/* return size of protocol address */

	freeaddrinfo(ressave);

	return(listenfd);
}
/* end tcp_listen */

