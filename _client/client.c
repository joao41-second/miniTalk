
#include <signal.h>
#include <fcntl.h>

#include "../libft/libft/libft.h"
#include "../libft/printf/ft_printf.h"


void	handlers(int sig, siginfo_t *info, void *ucontext)
{
	// if(sig == SIGUSR1 )
	// 	write(1,"ola\n",4);
	// else
	// 	write(1,"ola\n",4);
  
}

static void server()
{
 struct sigaction sa;
 static int a ;
 a = 0;

 sigemptyset(&sa.sa_mask);

 sa.sa_sigaction = handlers;
 sa.sa_flags = SA_RESTART;

  //ft_printf("PID e = %d \n",getpid());

 sigaction(SIGUSR1,&sa,NULL);
 sigaction(SIGUSR2,&sa,NULL);
}

static void env_bit(char *str,pid_t ok)
{
  int i;
  i = -1;
  
  while(str[++i] != '\0')
  {
    if(str[i] == '0')
      kill(ok,SIGUSR1);
    if (str[i]== '1')
      kill(ok,SIGUSR2);
    server();
    usleep(1000);
  }

}

int main(int ac ,char **av )
{
  if ( ac == 3)
  {
    int i;
    char b[9];
    i= -1;
    pid_t server_pid = ft_atoi(av[1]);
    while(av[2][++i] != '\0')
    {
      ft_bzero(b,9);
      ft_str_btis(8,av[2][i],b);
      
      ft_printf("bits - %s\n", b);
      env_bit(b,server_pid);
    }
    ft_bzero(b,9);
   
    ft_printf("bits - %s\n", "00000000");
    env_bit("00000000",server_pid);
    

  }
}
