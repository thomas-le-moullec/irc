##
## Makefile for Makefile in /home/le-dio_l/PSU_2016_myirc
## 
## Made by Leo Le Diouron
## Login   <le-dio_l@epitech.net>
## 
## Started on  Sat May 27 16:23:37 2017 Leo Le Diouron
## Last update Sat May 27 16:30:23 2017 Leo Le Diouron
##

NAME_SERVER		=		server

NAME_CLIENT		=		client

CC			=		gcc

RM			=		rm -rf

PATH_SERVER		=		./server/src/

PATH_CLIENT		=		./client/src/

SRCS_SERVER		=		$(PATH_SERVER)main.c		\

SRCS_CLIENT		=		$(PATH_CLIENT)main.c		\

OBJS_SERVER		=		$(SRCS_SERVER:.c=.o)

OBJS_CLIENT		=		$(SRCS_CLIENT:.c=.o)

CFLAGS			=		-W -Wall -Wextra $(INC)

INC			=		-I ./server/inc/ -I ./client/inc/

all:					$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):				$(OBJS_SERVER)
					$(CC) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT):				$(OBJS_CLIENT)
					$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT)

clean:
					$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:					clean
					$(RM) $(NAME_SERVER) $(OBJS_CLIENT)

re:					fclean all
