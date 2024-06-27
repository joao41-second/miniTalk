/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:31:45 by jperpect          #+#    #+#             */
/*   Updated: 2024/06/27 17:02:16 by jperpect         ###   ########.fr       */
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

int print_and_clear(t_list *save_list,char *save,int *len,int *index )
{
	ft_lstptint(save_list,1);
			ft_putstr_fd(save,1);
			ft_lstclear(&save_list);
			len[0] = 0;
			index[0] = 0;
			ft_bzero(save,11);
			return(0);
}



t_list *list_control(int *len,int *index,char *save)
{
	t_list *element;
	static t_list *list;
	static t_list *save_list ;
	len[0] = 0;
			usleep(50);
			if (index[0] == 0)
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
			index[0]++;
			return(save_list);
}


void	handlers(int sig, siginfo_t *info, void *ucontext)
{
	static  int ids = -1;
	static char letter[8] = "22222222";
	static  int len = 0;
	static  int index = 0;
	static t_list *save_list ;
	static char save[11];
	
	if(sig == SIGUSR1 )
		letter[++ids] = '0'; 	
	else if ( sig == SIGUSR2)
		letter[++ids] = '1';
	if (ids == 7)
	{
		concat(save,letter);
		if(ft_strncmp("00000000",letter,8) == 0)
			 ids = print_and_clear(save_list,save,&len,&index );
		ft_bzero(letter,8);
		if (len == 10)
			save_list = list_control(&len,&index,save);
		ids = -1;
		len++;
	}
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