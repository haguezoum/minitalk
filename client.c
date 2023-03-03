/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:46:27 by haguezou          #+#    #+#             */
/*   Updated: 2023/03/02 15:19:57 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(int ac, char *av[])
{
	int		pid;
	char	*msg;
	int		bits;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		msg = av[2];
		while (*msg)
		{
			bits = 8;
			while (--bits >= 0)
			{
				if ((((int)*msg >> bits) & 1) == 0)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(300);
			}
			usleep(150);
			msg++;
		}
	}
	return (0);
}
