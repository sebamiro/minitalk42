/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:55:40 by smiro             #+#    #+#             */
/*   Updated: 2022/11/10 16:06:11 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "includes/libft/libft.h"
#include "includes/printf/ft_printf.h"

int	g_bytes;

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		c |= 1;
	g_bytes++;
	if (g_bytes == 8)
	{
		ft_putchar_fd(c, 1);
		g_bytes = 0;
	}
	c <<= 1;
}

int	main(void)
{
	int	pid;
	struct sigaction	sa;

	pid = getpid();
	if (ft_printf("PID = %d\n", pid) < 0)
		return (0);
	g_bytes = 0;
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_RESTART;
	sa.sa_mask = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
