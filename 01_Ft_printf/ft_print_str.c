/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byungwook <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:44:46 by byungwook         #+#    #+#             */
/*   Updated: 2021/06/23 12:39:00 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_set_buff(char *str, t_data *data)
{
	int		index;
	char	*buff;
	int		end;

	if (data->prec < (int)ft_strlen(str))
		end = data->prec;
	else
		end = ft_strlen(str);
	if (!(buff = malloc(sizeof(char) * end + 1)))
		return (NULL);
	index = 0;
	while (index < end)
	{
		buff[index] = str[index];
		index++;
	}
	buff[index] = '\0';
	return (buff);
}

int		ft_s_width(t_data *data, char **buff)
{
	int		index;
	char	*box;

	if (data->width <= (int)ft_strlen(*buff))
		return ((int)ft_strlen(*buff));
	index = 0;
	box = malloc(sizeof(char) * (data->width - ft_strlen(*buff) + 1));
	while (index < data->width - (int)ft_strlen(*buff))
	{
		if (data->zero == 1)
			box[index] = '0';
		else
			box[index] = ' ';
		index++;
	}
	box[index] = '\0';
	if (data->minus == 0)
		*buff = ft_strjoin(box, *buff);
	else
		*buff = ft_strjoin(*buff, box);
	return (data->width);
}

int		ft_print_str(char *str, t_data *data)
{
	int		count;
	char	*buff;

	count = 0;
	if (!str)
		str = "(null)";
	if (data->prec == -1 || (size_t)data->prec > ft_strlen(str))
		data->prec = ft_strlen(str);
	buff = ft_set_buff(str, data);
	count = ft_s_width(data, &buff);
	ft_putstr_fd(buff, 1);
	free(buff);
	return (count);
}
