/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:55:42 by smiro             #+#    #+#             */
/*   Updated: 2022/11/10 17:10:02 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "includes/libft/libft.h"
#include "includes/printf/ft_printf.h"

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
		usleep(100);
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
	while (av[2][i])
	{
		sendchar(pid, av[2][i]);
		i++;
	}
	sendchar(pid, 0);
	return (0);
}
