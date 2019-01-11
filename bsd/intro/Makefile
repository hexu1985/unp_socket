RM = rm -f
CXX = g++
INCLUDE = -I../common
CXXFLAGS = -Wall -g -O2 ${INCLUDE}
LIBS = 
VPATH = ../common

PROGS =	daytimetcpcli daytimetcpsrv

all:	${PROGS}

daytimetcpcli:	daytimetcpcli.o err_quit.o
		${CXX} ${CXXFLAGS} -o $@ $^

daytimetcpsrv:	daytimetcpsrv.o err_quit.o
		${CXX} ${CXXFLAGS} -o $@ $^

clean:
		rm -f ${PROGS} ${CLEANFILES} *.o

distclean:
		rm -f ${PROGS} ${CLEANFILES} *.o
