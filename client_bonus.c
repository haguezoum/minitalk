/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:31:44 by haguezou          #+#    #+#             */
/*   Updated: 2023/02/27 20:32:37 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	recived(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("recived succefuly !", 2);
	}
}

void	the_end_of(int pid)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		kill(pid, SIGUSR1);
		usleep(150);
	}
}

int	main(int ac, char *av[])
{
	char	*msg;
	int		bits;

	signal(SIGUSR1, recived);
	if (ac == 3)
	{
		msg = av[2];
		while (*msg)
		{
			bits = 8;
			while (--bits >= 0)
			{
				if ((((int)*msg >> bits) & 1) == 0)
					kill(ft_atoi(av[1]), SIGUSR1);
				else
					kill(ft_atoi(av[1]), SIGUSR2);
				usleep(150);
			}
			msg++;
		}
		the_end_of(ft_atoi(av[1]));
	}
	return (0);
}
