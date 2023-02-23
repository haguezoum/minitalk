/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:30:07 by haguezou          #+#    #+#             */
/*   Updated: 2023/02/22 15:48:39 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int power(int n)
{
  int tot;
  tot = 1;
  while(n)
  {
    tot = tot * 2;
    n--;
  }
  return tot;
}

int convert(unsigned char *str)
{
    int sum;
    int i;
    sum = 0;
    i = 0;

    while(str[i])
    {                                            
        if(str[i] == '1')
        {
            sum = sum + power(7-i);
        }
        i++;
    }
    return (sum);
}


void handler(int sig, siginfo_t *info , void *unsend)
{
    static unsigned char bits[8];
    static int byte ;
    static int senderPID;
    
    if(senderPID != info->si_pid)
        byte = 0;
    senderPID = info->si_pid;
    if(sig == SIGUSR1)    
        bits[byte++] = '0';
    else
        bits[byte++] = '1';
    if(byte == 8)
    {  
        byte = 0;
        ft_printf("%c",convert(bits));
    }
}

int main()
{
    printf("%d\n",getpid());
    struct sigaction sa;
    sa.sa_sigaction =  handler;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    while (1)
    {
        pause();
    }
    
}
