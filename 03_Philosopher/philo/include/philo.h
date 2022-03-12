#ifndef PHILO_H
# define PHILO_H

/*  Header */
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

/* Structure */
typedef struct s_philo
{
	int				seat;

	int				is_eating;
	int				left_fork;
	int				right_fork;
	int				count_eat;

	long long		latest_eat;

	pthread_mutex_t	mtx;
	pthread_mutex_t	eat;

	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	int				done;

	int				num_philos;
	int				must_eat_count;

	long long		time_die;
	long long		time_eat;
	long long		time_sleep;

	struct timeval	start;

	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	check;
}			t_data;

/* Function */
int			ft_atoi(const char *str);
int			myalloc(void *ret, size_t size);
int			p_error(t_data *data, char *str);
void		all_free(t_data *data);
long long	time_ms(struct timeval now);
void		ft_sleep(long long ms);
int			print_msg(t_philo *philo, char *str, int dead);

void		pick_fork(t_philo *philo);
void		leave_fork(t_philo *philo);
void		eating(t_philo *philo);

void		*monitor_count(void *av);
void		*monitor_dead(void *av);
void		*routine(void *av);

#endif
