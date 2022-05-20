#include "../include/philo.h"


void	terminate_program(t_data *data)
{
	pthread_mutex_lock(&data->shared_mutex);
	data->is_finished = 1;
	pthread_mutex_unlock(&(data->shared_mutex));
}

void destroy_and_free(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&(data->shared_mutex));
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks_mutex[i]);
		i++;
	}
	i = 0;
	while(i < data->number_of_philo)
	{
		if (data->philos[i] != NULL)
			free(data->philos[i]);
		if (data->monitors[i] != NULL)
			free(data->monitors[i]);
		i++;
	}
	if (data->philos != NULL)
		free(data->philos);
	if (data->monitors != NULL)
		free(data->monitors);
	pthread_mutex_unlock(&(data->shared_mutex));
	pthread_mutex_destroy(&data->shared_mutex);
}

int	main(int argc, char **argv)
{
	t_data data;

	memset(&data, 0, sizeof(t_data));
	if ((argc != 5 && argc != 6) || ft_isnum(argc - 1, argv) == false || digit_check(argc, argv) == false)
	{
		printf(RED"Invalid input!\n");
		print_help();
		return (0);
	}
	if(init_data(&data, argc, argv) == false)
		return (0);
	create_thread(&data);
	join_thread(&data);
	destroy_and_free(&data);
}
