/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:53:07 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 12:47:10 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_c_width(t_data *data)
{
	int		count;
	int		num;

	count = 0;
	num = 0;
	while (num < data->width - 1)
	{
		if (data->zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		num++;
		count++;
	}
	return (count);
}

int		ft_print_char(int c, t_data *data)
{
	int		count;

	count = 0;
	if (data->type == '%' && data->minus == 1)
		data->zero = 0;
	if (data->minus == 1)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	count += ft_c_width(data);
	if (data->minus == 0)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}
