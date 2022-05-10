#include "../include/philo.h"



void	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philo = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->number_of_min_eat = atoi[5];
	else
		data->number_of_min_eat = 0;
	pthread_mutex_init(&(data->shared_mutex), NULL);
	init_philos(data);
	init_forks(data);
	init_monitor(data);
	return ;
}