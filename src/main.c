#include "../include/philo.h"

//__attribute__((destructor))
//static void destructor() {
//	system("leaks -q philo");
//}


void	terminate_program(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&data->shared_mutex);
	data->is_finished = 1;
	pthread_mutex_unlock(&(data->shared_mutex));
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks_mutex[i]);
		i++;
	}
	pthread_mutex_unlock(&(data->shared_mutex));
	pthread_mutex_destroy(&data->shared_mutex);
/*	while(i < data->number_of_philo)
	{
		pthread_mutex_destroy(&(data->forks_mutex[i]));
		if (data->philos[i] != NULL)
			free(data->philos[i]);
		if (data->monitors[i] != NULL)
			free(data->monitors[i]);
		i++;
	}
	if (data->philos != NULL)
		free(data->philos);
	if (data->monitors != NULL)
		free(data->monitors);*/
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 5 && argc != 6)
		put_error("invalid arguments");
	init_data(&data, argc, argv);
	create_thread(&data);
	join_thread(&data);
}

