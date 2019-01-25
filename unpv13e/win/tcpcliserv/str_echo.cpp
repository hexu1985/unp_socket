#include "str_echo.hpp"

#include <stdio.h>

#include "config.hpp"
#include "err_msg.hpp"
#include "send_all.hpp"

void
str_echo(SOCKET sockfd)
{
	ssize_t		n;
	char		buf[MAXLINE];

	while ( (n = recv(sockfd, buf, MAXLINE, 0)) > 0)
		send_all(sockfd, buf, n);

	if (n == SOCKET_ERROR)
        err_msg("str_echo: read error");
}
