/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:02:06 by bypark            #+#    #+#             */
/*   Updated: 2021/06/26 10:59:24 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

static void		handle_sigusr1(int sig)
{
	(void)sig;
	g_msg.str[g_msg.bit / 8] |= (0x80 >> (g_msg.bit % 8));
	g_msg.bit++;
}

static void		handle_sigusr2(int sig)
{
	(void)sig;
	g_msg.str[g_msg.bit / 8] ^= (0x80 >> (g_msg.bit % 8));
	g_msg.bit++;
}

int				main(void)
{
	int			enter;

	g_msg.bit = 0;
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	g_msg.str[LEN] = '\0';
	ft_memset(g_msg.str, 0xFF, LEN);
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	while (1)
	{
		if (g_msg.bit != 0 && (g_msg.str[((g_msg.bit - 1) / 8)] == 0
			|| ((g_msg.bit) / 8) >= LEN))
		{
			enter = (((g_msg.bit) / 8) < LEN) ? 1 : 0;
			g_msg.bit = 0;
			ft_putstr_fd(g_msg.str, 1);
			if (enter)
				ft_putchar_fd('\n', 1);
			ft_memset(g_msg.str, 0xFF, LEN);
		}
	}
}
