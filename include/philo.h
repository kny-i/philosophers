#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include "sys/time.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdbool.h"
# include "pthread.h"
# include "limits.h"

typedef struct s_data t_data;

typedef struct s_philo
{
	bool	has_fork_right;
	bool	has_fork_left;
	size_t 	eat_count;
	size_t	philo_number;
	size_t	last_eat_time;
	pthread_t	thread_philo;
	t_data		*data;
}	t_philo;

typedef struct s_monitor
{
	size_t	monitor_number;

	pthread_t	thread_monitor;
	t_data		*data;
	t_philo		*philo;
}	t_monitor;

typedef struct s_data
{
	size_t	number_of_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_min_eat;
	t_philo			**philos;
	t_monitor		**monitors;
	pthread_mutex_t	shared_mutex;
	pthread_mutex_t	*forks_mutex;
}	t_data;

void	put_error(char *str);
void	init_data(t_data *data, int argc, char **argv);
void 	create_thread(t_data *data);
void	join_thread(t_data *data);
size_t	get_time(t_data *data);
void	print_action(t_philo *philo, char *message);
void	pickup_fork(t_philo *philo);
void	time_keeper(t_data *data, size_t time);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	*monitor_routine(void *ptr);
#endif