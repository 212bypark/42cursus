#include "../include/philo.h"

long long	time_ms(struct timeval now)
{
	long long	ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}

static int	current_ms(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (time_ms(now));
}

void	ft_sleep(long long ms)
{
	long long	start;

	start = current_ms();
	while (current_ms() - start < ms)
		usleep(100);
	return ;
}
