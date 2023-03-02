/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:44:33 by haguezou          #+#    #+#             */
/*   Updated: 2023/03/01 22:04:08 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (*string)
	{
		i++;
		string++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	print_each_number(unsigned int num, int fd)
{
	char	c;

	if (num <= 0)
		return ;
	print_each_number(num / 10, fd);
	c = num % 10 + '0';
	write(fd, &c, 1);
}
