/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:31:45 by jperpect          #+#    #+#             */
/*   Updated: 2024/06/24 09:53:55 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "../libft/libft/libft.h"
#include "../libft/printf/ft_printf.h"

char	*ft_concatenat_str(char *orig, char *second)
{
	int		len;
	int		i;
	char	*ret;
	int		origs;

	origs = ft_strlen(orig);
	i = -1;
	len = origs + ft_strlen(second) + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, len);
	if (orig != NULL)
	{
		while (orig[++i] != '\0')
			ret[i] = orig[i];
		free(orig);
	}
	i = -1;
	while (second[++i] != '\0')
		ret[origs + i] = second[i];
	ret[origs + i] = '\0';
	return (ret);
}

static char atoi_base(char *nbr,int base)
{
	int i;
	int valeu;
	valeu = 0;
	i = 0;
	while(nbr[++i] != '\0')
	{
		valeu = valeu * base + nbr[i]-'0';	
	}
		valeu = -(valeu);
	return(valeu);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	cont;
	char	*str;

	cont = 0;
	str = (char *)s;
	while (cont < n)
	{
		str[cont] = '2';
		cont++;
	}
}


// void	handlers(int sig, siginfo_t *info, void *ucontext)
// {
// 	static int ids = 0;
// 	static char letra[8] = "22222222";
// 	static int len = 0;
// 	static char *save = "";
// 	char *temp;
// 	//temp = save;

// 	if(sig == SIGUSR1 )
// 		letra[ids] = '0'; 	
// 	else
// 		letra[ids] = '1';
	
// 	if (ids == 7)
// 	{
		
// 		char let = -(atoi_base(letra,2));
// 		ft_printf(" %s\n",letra);
// 		ft_bzero(letra,8);
		
// 		//ft_printf(" %c\n",let);
		
// 		ids = -1;
// 		//temp = ft_strdup(save);
// 		//save = ft_strjoin(temp,&let);
// 		//ft_printf(" %s\n",save);
		
// 		//ft_concatenat_str(temp,"a");
		
// 	}
// 	kill(info->si_pid,SIGUSR1);
// 	ids++;
// 	len++;
	
// }
void	handlers(int sig, siginfo_t *info, void *ucontext)
{
	static int ids = 0;
	static char letra[8] = "22222222";
	static int len = 0;
	
	 static char *save  = NULL;
	 char *temp;
	
	if(sig == SIGUSR1 )
		letra[ids] = '0'; 	
	else
		letra[ids] = '1';
	
	if (ids == 7)
	{
		char let = -(atoi_base(letra,2));
		char le[2];
		le[0]= let;
		le[1]='\0';

		 if (save == NULL)
		 {
			temp = ft_strdup("");
		 }
		 else 
		 	temp = ft_strdup(save);
			
		 //ft_printf(" temp = %s let = %s \n",temp, le);
 		 save = ft_concatenat_str(temp,le);
		 ft_bzero(letra,8);
		 ft_printf(" %s\n",save);
		ids = -1;
	}
	kill(info->si_pid,SIGUSR1);
	ids++;
	len++;
	
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
	close(fd);
	
	
	ft_printf("PID e = %d \n",getpid());
	
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL);
	

	while(1)
	{
		pause();
	}


}