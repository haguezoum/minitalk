/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:25:18 by haguezou          #+#    #+#             */
/*   Updated: 2023/03/01 16:41:40 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_bzero(void *string, size_t n)
{
	while (n != 0)
	{
		*(char *)string = '\0';
		n--;
		string++;
	}
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

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr == 0)
		write(fd, "0", 1);
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	print_each_number(nbr, fd);
}

int	ft_atoi(const char *str)
{
	long	res;
	size_t	i;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		if ((res > 2147483647) && sign == 1)
			return (-1);
		if ((res > 2147483648) && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

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
