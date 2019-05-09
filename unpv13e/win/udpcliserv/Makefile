RM = rm -f
CXX = g++
INCLUDE = -I../common
CXXFLAGS = -Wall -g -O2 ${INCLUDE} -std=c++11 -D_WIN32_WINNT=0x0600	# _WIN32_WINNT for inet_ntop
LIBS = -lpthread -lwsock32 -lws2_32
VPATH = ../common

PROGS =	udpcli udpserv

all:	${PROGS}

udpcli:	udpcli.o dg_cli.o err_quit.o
		${CXX} ${CXXFLAGS} -o $@ $^ ${LIBS}

udpserv: udpserv.o dg_echo.o send_all.o err_quit.o
		${CXX} ${CXXFLAGS} -o $@ $^ ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES} *.o

distclean:
		rm -f ${PROGS} ${CLEANFILES} *.o
