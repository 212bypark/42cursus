/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:45:09 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 12:45:33 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_type(t_data *data)
{
	int		count;
	char	type;

	count = 0;
	type = data->type;
	if (type == 'c')
		count = ft_print_char(va_arg(data->ap, int), data);
	else if (type == 's')
		count = ft_print_str(va_arg(data->ap, char *), data);
	else if (type == 'p')
		count = ft_print_nbr(va_arg(data->ap, unsigned long long), data);
	else if (type == 'd' || type == 'i')
		count = ft_print_nbr(va_arg(data->ap, int), data);
	else if (type == 'u' || type == 'x' || type == 'X')
		count = ft_print_nbr(va_arg(data->ap, unsigned int), data);
	else if (type == '%')
		count = ft_print_char('%', data);
	return (count);
}
