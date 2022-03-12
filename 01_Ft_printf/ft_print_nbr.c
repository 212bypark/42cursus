/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:51:22 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 17:48:34 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_n_prec(unsigned long long num, t_data *data, char **buff)
{
	int		len;
	int		total;
	int		index;

	len = ft_nbr_len(num, data);
	total = (data->prec > len) ? data->prec : len;
	if (!(*buff = (char *)malloc(sizeof(char) * total + 1)))
		return (0);
	(*buff)[total] = '\0';
	index = 0;
	while (len + index < total)
	{
		(*buff)[index] = '0';
		index++;
	}
	if (num == 0 && data->prec != 0)
		(*buff)[total - 1] = '0';
	index = 1;
	while (num)
	{
		(*buff)[total - index] = ft_base(data->type)[num % data->num_base];
		num /= data->num_base;
		index++;
	}
	return (total);
}

static int	ft_put_sign_nonz(t_data *data, char **buff)
{
	int		len;

	len = 0;
	if ((data->type == 'd' || data->type == 'i') &&
			data->zero == 0 && data->num_sign == -1)
	{
		*buff = ft_strjoin("-", *buff);
		len++;
	}
	return (len);
}

static int	ft_put_sign_zero(t_data *data, char **buff, int buff_len)
{
	int		len;

	len = 0;
	if (data->num_sign == -1 && data->zero == 1)
	{
		if (buff_len >= data->width)
		{
			*buff = ft_strjoin("-", *buff);
			len++;
		}
		else if (buff_len < data->width)
			*buff[0] = '-';
	}
	return (len);
}

static int	ft_put_fix(char **buff)
{
	int		len;

	*buff = ft_strjoin("0x", *buff);
	len = 2;
	return (len);
}

int			ft_print_nbr(unsigned long long num, t_data *data)
{
	int		count;
	char	*buff;
	int		len;

	len = 0;
	if (data->type == 'x' || data->type == 'X' || data->type == 'p')
		data->num_base = 16;
	if ((data->type == 'd' || data->type == 'i') && (int)num < 0)
	{
		data->num_sign = -1;
		num *= -1;
	}
	if (data->type == 'u')
		num = (unsigned int)num;
	len += ft_n_prec(num, data, &buff);
	len += ft_put_sign_nonz(data, &buff);
	if (data->type == 'p')
		len += ft_put_fix(&buff);
	count = ft_s_width(data, &buff);
	count += ft_put_sign_zero(data, &buff, len);
	ft_putstr_fd(buff, 1);
	free(buff);
	return (count);
}
