#include "../include/philo.h"

static void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i].seat = i;
		data->philos[i].is_eating = 0;
		data->philos[i].count_eat = 0;
		if (i == 0)
			data->philos[i].right_fork = data->num_philos - 1;
		else
			data->philos[i].right_fork = i - 1;
		data->philos[i].left_fork = i;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].mtx, NULL);
		pthread_mutex_init(&data->philos[i].eat, NULL);
		pthread_mutex_lock(&data->philos[i].eat);
	}
}

static int	init_mutex(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->check, NULL);
	pthread_mutex_lock(&data->check);
	if (myalloc(&data->forks, sizeof(pthread_mutex_t) * data->num_philos))
		return (p_error(NULL, "Memory alloction failed."));
	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	return (0);
}

static int	init_threads(t_data *data)
{
	int			i;
	pthread_t	thread;
	void		*philo;

	gettimeofday(&data->start, NULL);
	if (data->must_eat_count > 0)
	{
		if (pthread_create(&thread, NULL, monitor_count, data))
			return (1);
		pthread_detach(thread);
	}
	i = -1;
	while (++i < data->num_philos)
	{
		philo = (void *)(&data->philos[i]);
		if (pthread_create(&thread, NULL, routine, philo))
			return (1);
		pthread_detach(thread);
	}
	pthread_join(thread, NULL);
	return (0);
}

static int	parsing(int ac, char **av, t_data *data)
{
	data->num_philos = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->must_eat_count = 0;
	if (ac == 6)
		data->must_eat_count = ft_atoi(av[5]);
	data->forks = NULL;
	if (myalloc(&data->philos, sizeof(t_philo) * data->num_philos))
	{
		data->done = -1;
		return (p_error(NULL, "Memory alloction failed."));
	}
	data->done = 0;
	init_philos(data);
	return (init_mutex(data));
}

int	main(int ac, char **av)
{
	char	*str;
	int		i;
	t_data	data;

	if (ac != 5 && ac != 6)
		return (p_error(NULL, "Bad Arguments"));
	i = 0;
	while (av[++i])
	{
		str = av[i];
		if (*str == '0')
			return (p_error(NULL, "Bad Arguments"));
		while (*str)
		{
			if (!(*str >= '0' && *str <= '9'))
				return (p_error(NULL, "Bad Arguments"));
			str++;
		}
	}
	if (parsing(ac, av, &data))
		return (p_error(&data, "Parsing Error"));
	if (init_threads(&data))
		return (p_error(&data, "Thread Error"));
	pthread_mutex_lock(&data.check);
	all_free(&data);
	return (0);
}
