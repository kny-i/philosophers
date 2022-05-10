#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_conf	t_conf;

typedef struct s_philo
{
	size_t			id;
	size_t			eat_count;
	size_t			last_eat_ms;
	bool			has_right_fork;
	bool			has_left_fork;
	pthread_t		thread;
	t_conf			*conf;
}	t_philo;

typedef struct s_monitor
{
	size_t			id;
	pthread_t		thread;
	t_philo			*philo;
	t_conf			*conf;
}	t_monitor;

typedef struct s_conf
{
	size_t			num_philos;
	size_t			die_ms;
	size_t			eat_ms;
	size_t			sleep_ms;
	size_t			num_must_eat;
	size_t			num_full_philos;
	bool			finish_flag;
	pthread_mutex_t	m_common;
	t_monitor		**monitor;
	t_philo			**philo;
	pthread_mutex_t	**m_forks;
}	t_conf;

#endif