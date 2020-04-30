##
## EPITECH PROJECT, 2020
## message_queue
## File description:
## Makefile
##

CC			=	g++

NAMEC		=	client
NAMES		=	server

SRCC		=	client.cpp
SRCS		=	server.cpp

OBJC		=	$(SRCC:.cpp=.o)
OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS	=	-lrt

all:	$(NAMEC) $(NAMES)

$(NAMEC):	$(OBJC)
	$(CC) -o $(NAMEC) $(OBJC) $(CPPFLAGS)

$(NAMES):	$(OBJS)
	$(CC) -o $(NAMES) $(OBJS) $(CPPFLAGS)

clean:
	rm -f $(OBJC)
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAMEC)
	rm -f $(NAMES)

re:	fclean all

.PHONY:	all	clean fclean re
