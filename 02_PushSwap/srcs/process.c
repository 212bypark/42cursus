#include "../include/pushswap.h"

int	free_process(t_data *data)
{
	while (data->a->head)
		free(pop(data->a));
	free(data->a);
	while (data->b->head)
		free(pop(data->b));
	free(data->b);
	if (data->arr)
		free(data->arr);
	if (data->origin)
		free(data->origin);
	free(data);
	return (0);
}

void	error_process(t_data *data)
{
	ft_putstr_fd("Error\n", 1);
	free_process(data);
	exit(1);
}

int	get_int(t_data *data, const char *str)
{
	int			sign;
	long long	num;

	num = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if ((*str == '-' || *str == '+') && *(str++) == '-')
		sign *= -1;
	if (ft_strlen(str) > 10 || ft_strlen(str) == 0)
		error_process(data);
	while ('0' <= *str && *str <= '9')
		num = num * 10 + *(str++) - '0';
	if (*str || (long long)(num * sign) < (long long)MIN_INT
		|| (long long)MAX_INT < (long long)(num * sign))
		error_process(data);
	return (num * sign);
}
