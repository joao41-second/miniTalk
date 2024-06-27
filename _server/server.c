/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:31:45 by jperpect          #+#    #+#             */
/*   Updated: 2024/06/27 16:20:41 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "../libft/libft/libft.h"
#include "../libft/printf/ft_printf.h"


void concat(char *str,char *bits)
{
	int a = 9;
	int zero;
	zero = 0;
	int i = 0;
	while(--a >= 0)
	{
		if(bits[i] == '1')
	 		zero = (zero<<1) | 1 ;
		else if(bits[i] == '0')
			zero= zero<<1;
		i++;
	}
	int len = ft_strlen(str);
	str[len] = zero;
	str[len+1] = '\0';
}






void	handlers(int sig, siginfo_t *info, void *ucontext)
{

	//int fd = open("file.ret", O_WRONLY | O_CREAT, 0644 );
	int fd = 1;
	static long int ids = 0;
	static char letra[8] = "22222222";
	static long int len = 0;
	static long int index = 0;

	static t_list *list;
	static t_list *save_list ;
	
	t_list *element;
	static char save[11];
	
	if(sig == SIGUSR1 )
		letra[ids] = '0'; 	
	else if ( sig == SIGUSR2)
		letra[ids] = '1';
	
	if (ids == 7)
	{
		
		concat(save,letra);
		
		
		if(ft_strncmp("00000000",letra,8) == 0)
		{
			ft_lstptint(save_list,fd);
			ft_putstr_fd(save,fd);
			ft_lstclear(&save_list);
			len = 0;
			index =0;
			ids = 0;
			ft_bzero(save,11);
			
		}
		ft_bzero(letra,8);

		if (len == 10)
		{
			len = 0;
			//ft_printf("%s",save);
			 usleep(50);
			if (index == 0)
			{
				list = ft_lstnew(ft_strdup(save));;
				
				save_list = list;		
			}
			else
			{
			element = ft_lstnew(ft_strdup(save));		
			ft_lstadd_back(&list,element);		
			list = list->next;
			}
			ft_bzero(save,11);
		
			index++;
		}
		ids = -1;
		len++;
	}
	ids++;
	kill(info->si_pid,SIGUSR1);
	
	
}


// int main()
// {
// 	struct sigaction sa;
	

// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_sigaction = handlers;
// 	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	



// 	printf("PID e = %d \n",getpid());
	
	
// 	ft_putnbr_fd(getpid(),1);	
// 	sigaction(SIGUSR1,&sa,NULL);
// 	sigaction(SIGUSR2,&sa,NULL);

// 	while(1)
// 	{
// 		pause();
// 	}


// }

int main()
{

	remove("number.txt");
	
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handlers;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	
	

	int fd = open("number.txt", O_WRONLY | O_CREAT, 0644 );
	
	ft_putnbr_fd(getpid(),fd);	
	ft_printf("💥 len %d",ft_strlen("💥"));
	char *a = "💥";	
	ft_putstr_fd(a,1);
	close(fd);
	
	
	ft_printf("PID e = %d \n",getpid());
	
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL);
	

	while(1)
	{
		pause();
	}


}