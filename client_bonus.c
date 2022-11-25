/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:55:42 by smiro             #+#    #+#             */
/*   Updated: 2022/11/10 19:37:14 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "includes/libft/libft.h"
#include "includes/printf/ft_printf.h"

void	confirm_signal(int signal)
{
	static int	i = 0;

	if (signal == SIGUSR1)
			i++;
	ft_printf("\r[%d]", i);
	if (signal == SIGUSR2)
	{
		ft_printf("\rTotal %d\n", i);
		exit(0);
	}
}

static void	sendchar(int pid, char c)
{
	int	i;
	int	signal;

	i = 0;
	signal = 0;
	while (i < 8)
	{
		if (c & 128)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal))
			exit(-1);
		pause();
		usleep(50);
		i++;
		c <<= 1;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
		return (0);
	pid = atoi(av[1]);
	signal(SIGUSR1, confirm_signal);
	signal(SIGUSR2, confirm_signal);
	while (av[2][i])
	{
		sendchar(pid, av[2][i]);
		i++;
	}
	sendchar(pid, 0);
	while (1)
		pause();
	return (0);
}
