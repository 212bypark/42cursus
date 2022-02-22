/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:51:41 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 18:00:54 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_init_data(t_data *data)
{
	data->type = 0;
	data->minus = 0;
	data->zero = 0;
	data->width = 0;
	data->prec = -1;
	data->num_sign = 0;
	data->num_base = 10;
}

static void	ft_set_wp(t_data *data, char *format)
{
	if (ft_isdigit(format[data->i]))
	{
		if (data->prec == -1)
			data->width = data->width * 10 + format[data->i] - 48;
		else
			data->prec = data->prec * 10 + format[data->i] - 48;
	}
	else if (format[data->i] == '*')
	{
		if (data->prec == -1)
		{
			data->width = va_arg(data->ap, int);
			if (data->width < 0)
			{
				data->minus = 1;
				data->width *= -1;
			}
		}
		else
			data->prec = va_arg(data->ap, int);
	}
}

static void	ft_check_flag(t_data *data, char *format)
{
	if (format[data->i] == '0' && data->width == 0 && data->prec == -1)
		data->zero = 1;
	else if (format[data->i] == '-')
		data->minus = 1;
	else if (format[data->i] == '.')
		data->prec = 0;
	else if (ft_isdigit(format[data->i]) || format[data->i] == '*')
		ft_set_wp(data, format);
	data->i++;
}

static int	ft_set_format(t_data *data, char *format)
{
	int		count;

	count = 0;
	while (format[data->i] != '\0')
	{
		while (format[data->i] != '%' && format[data->i])
		{
			ft_putchar_fd(format[data->i++], 1);
			count++;
		}
		if (format[data->i] == '%')
		{
			ft_init_data(data);
			data->i++;
			while (format[data->i] && !ft_strchr("cspdiuxX%", format[data->i]))
				ft_check_flag(data, format);
			if (format[data->i] == '\0')
				return (0);
			data->type = format[data->i++];
			if ((data->minus == 1 || data->prec > -1) && data->type != '%')
				data->zero = 0;
			count += ft_print_type(data);
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	t_data	*data;
	int		count;

	count = 0;
	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	data->i = 0;
	va_start(data->ap, format);
	count = ft_set_format(data, (char *)format);
	va_end(data->ap);
	free(data);
	return (count);
}
