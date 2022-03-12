/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:48:45 by bypark            #+#    #+#             */
/*   Updated: 2021/05/11 10:36:52 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r');
}

int		ft_data_check(long long data, long long sign)
{
	if (data < 0 && sign == 1)
		return (-1);
	else if (data < 0 && sign == -1)
		return (0);
	else
		return (sign * data);
}

int		ft_atoi(const char *str)
{
	long long		sign;
	long long		data;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	sign = 1;
	data = 0;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		data = data * 10 + *ptr - '0';
		if (data < 0)
			break ;
		ptr++;
	}
	return (ft_data_check(data, sign));
}
