#include "../include/philo.h"

void	terminate_program(t_data *data)
{
	int i;

	i = 0;
	while(i < data->number_of_philo)
	{
		pthread_mutex_destroy(&(data->forks_mutex[i]));
		free(data->philos[i]);
		free(data->monitors[i]);
	}
	free(data->philos);
	free(data->monitors);
	pthread_mutex_destroy(&(data->shared_mutex));
	free(data);
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

