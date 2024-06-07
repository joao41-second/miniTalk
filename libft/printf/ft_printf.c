/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:10:30 by jperpect          #+#    #+#             */
/*   Updated: 2024/05/08 14:43:49 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int identifire(char id,va_list args)
{
	if(id == 'c')
		return(ft_putchar_fd( va_arg(args,int ),1));
	else if (id == 's')
		return(ft_putstr_fd(va_arg(args,char *),1));
	else if (id == 'p')
		return(ft_printp(va_arg(args,unsigned long )));
	else if (id == 'd')
	 	return(ft_putnbr_base(va_arg(args, int   ), "0123456789",0));
	else if (id == 'i')
		return(ft_putnbr_base(va_arg(args, int   ), "0123456789",0));
	else if (id == 'u')
	 return(ft_putnbr_base(va_arg(args, unsigned int  ), "0123456789",1));
	else if (id == 'x')
	 return(ft_putnbr_base(va_arg(args, unsigned   ), "0123456789abcdef",0));
	else if (id == 'X')
	 return(ft_putnbr_base(va_arg(args, unsigned   ), "0123456789ABCDEF",0));
	else if (id == '%')
	 return(ft_putchar_fd('%',1));
	return(0);
}


int ft_printf(const char *str, ...)
{	
	int cont;
	int add;
	int i;
	
	add =0;
	cont = 0;
	i = 0;
	
	va_list args;
	va_start(args, str);
	while(str[cont] != '\0')
	{
		if(str[cont] == '%')
		{
			add = add + identifire(str[cont+1],args);
			
			cont += 2;
				i+=2;
		}
		else
		 ft_putchar_fd(str[cont++],1);
	}
	va_end(args);
	return (cont +add- i);
}
// int main ()
// {
// 	void *ptr = (char *)0x7ffeefbff710; // Exemplo de ponteiro void *
	
// 	int a = ft_printf(" %c%p \n",'a',-1);
// 	int b = printf(" %c%p \n",'a',-1);
// 	//ft_putstr_fd(NULL,1);
// 	 printf("%d a,%d b ",a,b);
	
// }

