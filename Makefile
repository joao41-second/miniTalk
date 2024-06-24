# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2024/06/19 09:49:27 by jperpect         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

SERVER_FILES = ./_server/server.c

CLIENT_FILES = ./_client/client.c

OBJS_CLI = $(CLIENT_FILES:.c=.o)

OBJS_SER = $(SERVER_FILES:.c=.o)

LIB = ./libft/libft.a ./libft/libftprintf.a

AR = ar rcs

CC = cc 

RM = rm -f

CAT = cat number.txt 

BITS = Loremipsumdolorsitamet,consectetueradipiscingelit.Nullamfeugiat,turpisatpulvinarvulputate,eratliberot

SERVER_NAME = server

CLIENT_NAME = client

#.SILENT:

all: $(SERVER_NAME) $(CLIENT_NAME) 

$(SERVER_NAME) : $(OBJS_SER)
	cd libft && make compile && make 
	cc   $(OBJS_SER) $(LIB) -o $(SERVER_NAME)
	

$(CLIENT_NAME) : $(OBJS_CLI)
	cd libft && make compile && make 
	cc   $(OBJS_CLI) $(LIB) -o $(CLIENT_NAME)


bonus: $(OBJECT_B) $(NAME)
	ar rcs $(NAME) $^


clean:
	$(fclean)
	$(RM)  $(OBJS_SER)
	$(RM)  $(OBJS_CLI)
	cd ./libft && make clean

fclean: clean
	$(RM) $(SERVER_NAME) 
	$(RM) $(CLIENT_NAME)


re: fclean all

exec:
	cc	-g $(FLGS)  $(SRCS) $(BONUS) -lbsd

norm: 
	python3 -m c_formatter_42 -c $(BONUS)


.SILENT:

inicia:
	make && make start && make bit

start: 
	$(all)
	gnome-terminal -- bash -c ./$(SERVER_NAME)

bit: 
	./client $(shell cat number.txt ) $(BITS) 
	
