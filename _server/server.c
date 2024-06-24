/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:31:45 by jperpect          #+#    #+#             */
/*   Updated: 2024/06/24 16:54:24 by jperpect         ###   ########.fr       */
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

void	ft_btowe(void *s, size_t n)
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


char * compli_str(char *bin_letra,char *temp,char *save)
{
	    char let ;
		char le[2];
		let =  -(atoi_base(bin_letra,2));
		///printf("\n os bit -%s \n",bin_letra);
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
		 return(save);
		 
}


void	handlers(int sig, siginfo_t *info, void *ucontext)
{

	//int fd = open("file.ret", O_WRONLY | O_CREAT, 0644 );
	int fd = 1;
	static int ids = 0;
	static char letra[8] = "22222222";
	static int len = 0;
	static int index = 0;
	
	
	static t_list *list;
	static t_list *save_list ;
	
	t_list *element;

	
	 static char *save  = NULL;
	 char *temp;
	
	if(sig == SIGUSR1 )
		letra[ids] = '0'; 	
	else if ( sig == SIGUSR2)
		letra[ids] = '1';
	
	if (ids == 7)
	{
		usleep(100);
		
			
		save = compli_str(letra,temp,save);
		if(ft_strncmp("00000000",letra,8) == 0)
		{
			ft_lstptint(save_list,fd);
			ft_putstr_fd(save,fd);
		
		}
		ft_btowe(letra,8);
		//ft_printf(" %s\n",save);
		
		if (len == 10)
		{
			len = 0;
			element = ft_lstnew(save);
			if (index == 0)
			{
				list = ft_lstnew("");;
				save_list = list;
				
			}else{
		
			save = NULL;
			ft_lstadd_back(&list,element);
			//ft_printf("%s",element->content);
			list = list->next;
			}
			index++;
		}
		
		ids = -1;
		len++;
	}
	kill(info->si_pid,SIGUSR1);
	ids++;
	
	
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