/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:05:23 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 12:51:17 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_nbr_len(unsigned long long num, t_data *data)
{
	int		len;

	if (num == 0 && data->prec != 0)
		return (1);
	len = 0;
	while (num)
	{
		num /= data->num_base;
		len++;
	}
	return (len);
}

char	*ft_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
