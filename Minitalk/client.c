/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:03:17 by bypark            #+#    #+#             */
/*   Updated: 2021/06/26 10:59:03 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_end_str(int pid, int index)
{
	int		bit;

	bit = -1;
	while (++bit < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
		usleep(30);
	}
	if (index % LEN == LEN - 1)
	{
		usleep(100);
		ft_end_str(pid, index + 1);
	}
}

static void	ft_send_msg(int pid, char *msg)
{
	int		index;
	int		bit;

	index = 0;
	while (msg[index])
	{
		bit = -1;
		while (++bit < 8)
		{
			if ((msg[index] & (0x80 >> bit)) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR1) == -1)
				exit(1);
			usleep(30);
		}
		index++;
		if ((index != 0) && (index % LEN == 0))
			usleep(100);
	}
	ft_end_str(pid, index);
}

int			main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	ft_send_msg(pid, av[2]);
	return (0);
}
