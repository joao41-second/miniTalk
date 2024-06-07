/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:42:42 by jperpect          #+#    #+#             */
/*   Updated: 2024/05/07 15:48:31 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
    return(1);
}

/*
int main (void)
{
    ft_putchar_fd('a',1);
    ft_putchar_fd('\n',1);
    ft_putchar_fd('a',1);
}*/