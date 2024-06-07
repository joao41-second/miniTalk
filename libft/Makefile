# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 11:50:39 by jperpect          #+#    #+#              #
#    Updated: 2024/06/07 14:40:25 by jperpect         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

NAME = lib.a

AR = ar rcs

LIBFT_DIR = libft
PRINTF_DIR = printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = libft.a libftprintf.a

CC = cc

RM = rm -f

#.SILENT:

all: $(NAME)

$(NAME): $(SRCS) 
	cd $(LIBFT_DIR) && make
	mv $(LIBFT) .
	cd $(PRINTF_DIR) && make
	mv $(PRINTF) .
	$(AR) $@ $^ 
clean:
	$(RM) $(SRCS)
	

compile:
	cd $(LIBFT_DIR) && make
	mv $(LIBFT) .
	cd $(PRINTF_DIR) && make
	mv $(PRINTF) .

fclean: clean
	$(RM) $(NAME)

re: fclean all

exec:
	$(CC) -g $(SRCS) $(BONUS) -lbsd

norm:
	python3 -m c_formatter_42 -c $(SRCS)

test: compile all clean