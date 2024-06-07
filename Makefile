# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2024/06/07 15:41:05 by jperpect         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

SERVER_NAME = server

CLIENT_NAME = client

SERVER_FILES = ./_server/server.c

CLIENT_FILES = ./_client/client.c

OBJS_CLI = $(CLIENT_FILES:.c=.o)

OBJS_SER = $(SERVER_FILES:.c=.o)


AR = ar rcs

CC = cc 

RM = rm -f

CAT = cat number.txt 

BITS = 1

#.SILENT:

all: $(OBJS_SER) $(OBJS_CLI) 
	cd libft && make compile && make 
	cc -g  $(OBJS_SER)  ./libft/libft.a  -o $(SERVER_NAME)
	cc -g  $(OBJS_CLI) ./libft/libft.a  -o $(CLIENT_NAME)
	

bonus: $(OBJECT_B) $(NAME)
	ar rcs $(NAME) $^


clean:
	$(fclean)

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
	make start && make bit
	

start: 
	$(all)
	gnome-terminal -- bash -c ./$(SERVER_NAME)

bit: 
	./client $(shell cat number.txt ) $(BITS)
	
