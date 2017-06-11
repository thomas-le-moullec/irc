##
## Makefile for Makefile in /home/le-dio_l/PSU_2016_myirc
## 
## Made by Leo Le Diouron
## Login   <le-dio_l@epitech.net>
## 
## Started on  Sun May 28 14:15:02 2017 Leo Le Diouron
## Last update Sun Jun 11 15:01:16 2017 Leo Le Diouron
##

NAME_SERVER		=		server

NAME_CLIENT		=		client

CC			=		gcc

RM			=		rm -rf

PATH_SERVER		=		./Server/src/

PATH_CLIENT		=		./Client/src/

SRCS_SERVER		=		$(PATH_SERVER)main.c			\
					$(PATH_SERVER)initialisation.c		\
					$(PATH_SERVER)server.c			\
					$(PATH_SERVER)client.c			\
					$(PATH_SERVER)orders.c			\
					$(PATH_SERVER)tools.c			\
					$(PATH_SERVER)fill_queue.c		\
					$(PATH_SERVER)cmd_connection.c		\
					$(PATH_SERVER)cmd_list.c		\
					$(PATH_SERVER)cmd_message.c		\
					$(PATH_SERVER)cmd_join.c		\
					$(PATH_SERVER)cmd_quit.c		\

SRCS_CLIENT		=		$(PATH_CLIENT)main.c			\
					$(PATH_CLIENT)run_client.c		\
					$(PATH_CLIENT)add_client.c		\
					$(PATH_CLIENT)initialisation_client.c	\
					$(PATH_CLIENT)tools.c			\

OBJS_SERVER		=		$(SRCS_SERVER:.c=.o)

OBJS_CLIENT		=		$(SRCS_CLIENT:.c=.o)

CFLAGS			=		-W -Wall -Wextra $(INC)

INC			=		-I ./Server/inc/ -I ./Client/inc/

all:					$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):				$(OBJS_SERVER)
					$(CC) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT):				$(OBJS_CLIENT)
					$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT)

clean:
					$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:					clean
					$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:					fclean all
