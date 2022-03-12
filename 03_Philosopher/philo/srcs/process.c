#include "../include/philo.h"

void	*monitor_count(void *av)
{
	t_data			*data;
	int				i;
	int				total;
	struct timeval	now;

	data = av;
	total = 0;
	while (total < data->must_eat_count)
	{
		i = -1;
		while (++i < data->num_philos)
			pthread_mutex_lock(&data->philos[i].eat);
		total++;
	}
	pthread_mutex_lock(&data->write);
	gettimeofday(&now, NULL);
	printf("\e[0;92;40m%lld\t%s\e[0m\n", \
			time_ms(now) - time_ms(data->start), "Eating Count Reached");
	data->done = 1;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_unlock(&data->check);
	return (NULL);
}

void	*monitor_dead(void *av)
{
	t_philo			*philo;
	struct timeval	now;
	long long		gap;

	philo = av;
	while (philo->data->done == 0)
	{
		pthread_mutex_lock(&philo->mtx);
		gettimeofday(&now, NULL);
		gap = time_ms(now) - philo->latest_eat;
		if (!philo->is_eating && \
			gap >= philo->data->time_die)
		{
			print_msg(philo, "died.", 1);
			philo->data->done = 1;
			pthread_mutex_unlock(&philo->mtx);
			pthread_mutex_unlock(&philo->data->check);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mtx);
		usleep(500);
	}
	return (NULL);
}

void	*routine(void *av)
{
	t_philo			*philo;
	pthread_t		thread;
	struct timeval	now;

	philo = av;
	gettimeofday(&now, NULL);
	philo->latest_eat = time_ms(now);
	if (pthread_create(&thread, NULL, monitor_dead, philo))
		return (NULL);
	pthread_detach(thread);
	if (philo->seat % 2 == 1)
		usleep(philo->data->time_eat * 1000);
	while (philo->data->done == 0)
	{
		pick_fork(philo);
		eating(philo);
		leave_fork(philo);
	}
	pthread_join(thread, NULL);
	return (NULL);
}
