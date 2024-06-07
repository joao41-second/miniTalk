/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 03:54:28 by jperpect          #+#    #+#             */
/*   Updated: 2024/05/08 11:44:14 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printp(unsigned  long decimal )
{
	char *base = "0123456789abcdef";
	int a;
	
	a = 0;
	if (decimal == 0)
	 return(ft_putstr_fd("(nil)",1));
	ft_putstr_fd("0x",1);
	a = ft_putnbr_base(decimal ,base,1 );
	return(a +2);
}


/* int main()
{
	
void *ptr = (void *)0x7ffeefbff710;	
char test[] = "afdsfsadfasdfsadfasdfsdafsadfdasfsdafasdf";
void *pint = 'a';
ft_printp(test);
ft_putchar_fd('\n',1);
printf("%d",test );
printf("\n%p",test );

}  */