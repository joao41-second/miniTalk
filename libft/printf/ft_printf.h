
#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <aio.h>

int ft_printf(const char *formant, ...);

int ft_printp(unsigned long int decimal);

int ft_putnbr_base(  long int nbr, char *base,int neg);

int	ft_putchar_fd(char c, int fd);

int	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *s);


#endif