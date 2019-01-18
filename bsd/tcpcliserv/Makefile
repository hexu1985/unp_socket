RM = rm -f
CXX = g++
INCLUDE = -I../common
CXXFLAGS = -Wall -g -O2 ${INCLUDE} -std=c++11
LIBS = -lpthread
VPATH = ../common

PROGS =	tcpcli tcpserv

all:	${PROGS}

tcpcli:	tcpcli.o str_cli.o send_all.o recv_until.o err_quit.o
		${CXX} ${CXXFLAGS} -o $@ $^ ${LIBS}

tcpserv: tcpserv.o str_echo.o send_all.o err_quit.o
		${CXX} ${CXXFLAGS} -o $@ $^ ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES} *.o

distclean:
		rm -f ${PROGS} ${CLEANFILES} *.o
