#include "../include/philo.h"

int	myalloc(void *ret, size_t size)
{
	*(void **)ret = malloc(size);
	if (*(void **)ret == NULL)
		return (1);
	memset(*(void **)ret, 0, size);
	return (0);
}

int	p_error(t_data *data, char *str)
{
	if (data)
		all_free(data);
	printf("%s\n", str);
	return (1);
}

void	all_free(t_data *data)
{
	int	i;

	i = -1;
	if (data->done == -1)
		return ;
	if (data->philos)
	{
		while (++i < data->num_philos)
		{
			pthread_mutex_destroy(&data->philos[i].mtx);
			pthread_mutex_destroy(&data->philos[i].eat);
		}
		free(data->philos);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->check);
	if (data->done == 0)
		return ;
	i = -1;
	if (data->forks)
	{
		while (++i < data->num_philos)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
}

int	print_msg(t_philo *philo, char *str, int dead)
{
	struct timeval	now;
	long long		ms;

	pthread_mutex_lock(&philo->data->write);
	gettimeofday(&now, NULL);
	ms = time_ms(now) - time_ms(philo->data->start);
	if (philo->data->done == 0)
		printf("%lld\tPhilo[%d] %s\n", ms, philo->seat + 1, str);
	if (dead == 1)
		return (0);
	if (pthread_mutex_unlock(&philo->data->write))
		return (1);
	return (0);
}
