#include "../include/philo.h"

static bool	init_philos(t_data *data)
{
	int 	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i].has_fork_right = false;
		data->philos[i].has_fork_left = false;
		data->philos[i].eat_count = 0;
		data->philos[i].philo_number = i + 1;
		data->philos[i].data = data;
		i++;
	}
	return (true);
}

static bool	init_monitors(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->monitors[i].monitor_number = i + 1;
		data->monitors[i].data = data;
		data->monitors[i].philo = &data->philos[i];
		data->monitors[i].is_reached_min_eat = 0;
		i++;
	}
	return (true);
}

static bool	init_forks(t_data *data)
{
	int 	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_init(&(data->forks_mutex[i]), NULL);
		i++;
	}
	return (true);
}

bool	init_data(t_data *data, int argc, char **argv)
{
	if (ft_atoll(argv[1]) > 200)
	{
		printf(RED"too many philosophers \n");
		return (false);
	}
	data->number_of_philo = ft_atoll(argv[1]);
	data->time_to_die = ft_atoll(argv[2]);
	data->time_to_eat = ft_atoll(argv[3]);
	data->time_to_sleep = ft_atoll(argv[4]);
	data->argc = argc;
	data->is_finished = 0;
	if (argc == 6)
		data->number_of_min_eat = ft_atoll(argv[5]);
	else
		data->number_of_min_eat = 0;
	pthread_mutex_init(&(data->shared_mutex), NULL);
	if(!init_philos(data) || !init_forks(data) || !init_monitors(data))
	{
		printf(RED"malloc error\n");
		return (false);
	}
//	int i;

//	i = 0;
//	printf("shared_mutex -> [%p]\n", &data->shared_mutex);
//	while (i < data->number_of_philo)
//	{
//		printf("forx_mutex[%d] -> [%p]\n", i , &data->forks_mutex[i]);
//		i++;
//	}
	return (true);
}