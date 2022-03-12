#include "../include/philo.h"

void	pick_fork(t_philo *philo)
{
	if (philo->data->done == 1)
		return ;
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	print_msg(philo, "has taken a fork.", 0);
}

void	leave_fork(t_philo *philo)
{
	if (philo->data->done == 1)
		return ;
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	print_msg(philo, "is sleeping.", 0);
	ft_sleep(philo->data->time_sleep);
	print_msg(philo, "is thinking.", 0);
}

void	eating(t_philo *philo)
{
	struct timeval	now;

	if (philo->data->done == 1)
		return ;
	pthread_mutex_lock(&philo->mtx);
	print_msg(philo, "is\x1b[31m eating.\x1b[0m", 0);
	philo->is_eating = 1;
	philo->count_eat += 1;
	pthread_mutex_unlock(&philo->eat);
	gettimeofday(&now, NULL);
	philo->latest_eat = time_ms(now);
	ft_sleep(philo->data->time_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mtx);
}
