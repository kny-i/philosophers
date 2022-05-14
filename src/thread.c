#include "../include/philo.h"

void	*philo_mov(void *data)
{
	while(1)
	{
		pickup_fork(data);
		philo_eat(data);
		philo_sleep(data);
		philo_think(data);
	}
	return (NULL);
}

void create_thread(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&(data->philos[i]->thread_philo), NULL, &philo_mov, data->philos[i]);
		i++;
	}
}

void	join_thread(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i]->thread_philo, NULL);
		i++;
	}
}