#include "../include/philo.h"

static void	init_philos(t_data *data)
{
	size_t	i;

	data->philos = malloc(sizeof(t_philo *) * data->number_of_philo);//error handling
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i] = malloc(sizeof(t_philo));//error handling
		data->philos[i]->has_fork_right = false;
		data->philos[i]->has_fork_left = false;
		data->philos[i]->eat_count = 0;
		data->philos[i]->philo_number = i + 1;
		data->philos[i]->data = data;
		i++;
	}
}

static void	init_monitors(t_data *data)
{
	size_t	i;

	data->monitors = malloc(sizeof(t_monitor *) * data->number_of_philo);//error handling
	i = 0;
	while (i < data->number_of_philo)
	{
		data->monitors[i] = malloc(sizeof(t_monitor));
		data->monitors[i]->monitor_number = i + 1;
		data->monitors[i]->data = data;
		data->monitors[i]->philo = data->philos[i];
		i++;
	}
}

static void	init_forks(t_data *data)
{
	size_t	i;

	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);//error handling
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_init(&(data->forks_mutex[i]), NULL);
		i++;
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philo = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->number_of_min_eat = atoi(argv[5]);
	else
		data->number_of_min_eat = 0;
	pthread_mutex_init(&(data->shared_mutex), NULL);
	init_philos(data);
	init_forks(data);
	init_monitors(data);
	return ;
}