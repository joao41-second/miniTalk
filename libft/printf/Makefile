FLGS = -Wall -Wextra -Werror

NAME =libftprintf.a

AR = ar rcs

SRCS = ft_printf.c ft_printp.c ft_putnbr_base.c \
ft_putstr_fd.c ft_putchar_fd.c ft_strlen.c \
 

OBJECT = $(SRCS:.c=.o) 


CC = cc 

RM = rm -f


#.SILENT:

all: $(NAME)

$(NAME): $(OBJECT)
	$(AR) $@ $^

bonus: $(OBJECT_B) $(NAME)
	ar rcs $(NAME) $^

%.o:%.c libft.h
	cc -c $(FLGS) -o $@ $<  

clean:
	$(RM)  $(OBJECT) $(OBJECT_B)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

exec:
	cc	-g   $(SRCS) $(BONUS) -lbsd

norm: 
	python3 -m c_formatter_42 -c $(BONUS)