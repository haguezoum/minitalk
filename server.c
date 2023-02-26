/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:30:07 by haguezou          #+#    #+#             */
/*   Updated: 2023/02/26 18:02:01 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert(char *str)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (i < 8)
	{
		sum = (sum << 1) | (str[i] == '1');
		i++;
	}
	return (sum);
}

void	print_char(char *bits, int byte)
{
	int	i;

	i = -1;
	while (++i < byte)
	{
		ft_putchar_fd(convert(bits + (i * 8)), 2);
	}
}

void	byte_counter(int *byte, int sum)
{
	if (sum == 15)
		*byte = 4;
	else if (sum == 14)
		*byte = 3;
	else if (sum == 12)
		*byte = 2;
	else
		*byte = 1;
}

void	handler(int sig, siginfo_t *info, void *unsend)
{
	static char		bits[32];
	static int		byte ;
	static int		senderPID;
	static int		x;
	static int		sum;

	if (senderPID != info->si_pid)
    {
		byte = 0;
		x = 0;
		ft_bzero(bits, 31);
		senderPID = info->si_pid;
	}
	bits[x] = (sig == SIGUSR2) + 48;
	sum = (sum << 1) | (sig == SIGUSR2);
	x++;
	if	(x == 4)
		byte_counter(&byte, sum);
	if(x == (8 * byte))
	{
		print_char(bits, byte);
		sum = 0;
		x = 0;
	}
}

int	main()
{
	ft_putnbr_fd(getpid(), 2);
	struct sigaction sa;
	sa.sa_sigaction =  handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL);
	while (1)
		pause();
}
