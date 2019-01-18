#include "str_echo.hpp"

#include <sys/types.h>
#include <sys/socket.h>

#include <errno.h>

#include "config.hpp"
#include "err_quit.hpp"
#include "send_all.hpp"

void
str_echo(int sockfd)
{
	ssize_t		n;
	char		buf[MAXLINE];

again:
	while ( (n = recv(sockfd, buf, MAXLINE, 0)) > 0)
		send_all(sockfd, buf, n);

	if (n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err_quit("str_echo: read error");
}
