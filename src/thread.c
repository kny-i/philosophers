#include "../include/philo.h"

void	time_keeper(t_data *data, size_t time)
{
	size_t	start_time;
	size_t	passed_time;

	start_time = get_time(data);
	while (1)
	{
		passed_time = get_time(data);
		if (passed_time - start_time >= time)
			return ;
		usleep(100);
	}
}

void	*philo_mov(void *philo)
{
	while(1)
	{
		pickup_fork(philo);
		philo_eat(philo);
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