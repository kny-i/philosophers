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

void	*philo_routine(void *ptr)
{

	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->philo_number % 2 == 0)
		time_keeper(philo->data, 200);
	while(1)
	{
		pickup_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void create_thread(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&(data->philos[i]->thread_philo), NULL, &philo_routine, data->philos[i]);
		pthread_create(&(data->monitors[i])->thread_monitor, NULL, &monitor_routine, data->monitors[i]);
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