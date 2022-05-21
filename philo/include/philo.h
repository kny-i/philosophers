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
# include "string.h"

# define INT_MAX_RANGE 11

typedef struct s_data	t_data;

typedef struct s_philo
{
	bool		has_fork_right;
	bool		has_fork_left;
	size_t		eat_count;
	int			philo_number;
	size_t		last_eat_time;
	pthread_t	thread_philo;
	t_data		*data;
}	t_philo;

typedef struct s_monitor
{
	size_t		monitor_number;
	bool		is_reached_min_eat;
	pthread_t	thread_monitor;
	t_data		*data;
	t_philo		*philo;
}	t_monitor;

typedef struct s_data
{
	int				number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			start_time;
	size_t			time_to_sleep;
	size_t			number_of_min_eat;
	bool			is_finished;

	t_philo			philos[256];
	t_monitor		monitors[256];
	pthread_mutex_t	shared_mutex;
	pthread_mutex_t	forks_mutex[256];
	int				argc;
}	t_data;

//init.c
bool		init_data(t_data *data, int argc, char **argv);

//thread.c
void		create_thread(t_data *data);
void		join_thread(t_data *data);

//fork.c
int			pickup_fork(t_philo *philo);
void		put_down_fork(t_philo *philo);

//philo_action.c
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);
int			philo_eat(t_philo *philo);
void		*philo_routine(void *ptr);

//time.c
int			time_keeper_philo(t_philo *philo, size_t time);
size_t		get_time(void);

//monitor.c
void		*monitor_routine(void *ptr);
void		terminate_program(t_data *data);

//print_action.c
void		print_help(void);
size_t		get_time_philo(t_philo *philo);
int			print_action(t_philo *philo, char *message);

//utils.c
long long	ft_atoll(const char *str);
bool		digit_check(int argc, char **argv);
bool		ft_isnum(int size, char **s);
#endif