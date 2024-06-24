# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 11:50:39 by jperpect          #+#    #+#              #
#    Updated: 2024/06/24 10:39:55 by jperpect         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror


AR = ar rcs

LIBFT_DIR = libft
PRINTF_DIR = printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = libft.a libftprintf.a

CC = cc

RM = rm -f

.SILENT:

all: $(SRCS)

$(SRCS):
	cd $(LIBFT_DIR) && make bonus
	mv $(LIBFT) .
	cd $(PRINTF_DIR) && make 
	mv $(PRINTF) .
	$(AR) $@ $^ 
clean:
	$(RM) $(SRCS)
	cd $(LIBFT_DIR) && make clean
	cd $(PRINTF_DIR) && make clean
	
	
compile:
	cd $(LIBFT_DIR) && make bonus
	mv $(LIBFT) .
	cd $(PRINTF_DIR) && make
	mv $(PRINTF) .

fclean: clean
	$(RM) $(SRCS)
	
re: fclean all

exec:
	$(CC) -g $(SRCS) $(BONUS) -lbsd

norm:
	python3 -m c_formatter_42 -c $(SRCS)