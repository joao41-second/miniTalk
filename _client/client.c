/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:36:16 by jperpect          #+#    #+#             */
/*   Updated: 2024/06/28 13:38:03 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft/libft.h"
#include "../libft/printf/ft_printf.h"
#include <fcntl.h>
#include <signal.h>

void	handlers(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR2)
		ft_printf("fim de mensagem\n");
}

static void	server(void)
{
	struct sigaction	sa;
	static int			a;

	a = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handlers;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

static void	env_bit(char *str, pid_t ok)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '0')
			kill(ok, SIGUSR1);
		if (str[i] == '1')
			kill(ok, SIGUSR2);
		usleep(4000);
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	b[9];
	pid_t	server_pid;

	server();
	if (ac == 3)
	{
		i = -1;
		server_pid = ft_atoi(av[1]);
		while (av[2][++i] != '\0')
		{
			ft_bzero(b, 9);
			ft_str_btis(8, av[2][i], b);
			env_bit(b, server_pid);
		}
		ft_bzero(b, 9);
		env_bit("00000000", server_pid);
	}
}
