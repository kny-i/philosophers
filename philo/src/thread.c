#include "../include/philo.h"

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->number_of_philo)
	{
		pthread_create(&(data->philos[i].thread_philo), \
						NULL, &philo_routine, &data->philos[i]);
		pthread_create(&(data->monitors[i]).thread_monitor, \
						NULL, &monitor_routine, &data->monitors[i]);
		i++;
	}
}

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i].thread_philo, NULL);
		pthread_join(data->monitors[i].thread_monitor, NULL);
		i++;
	}
}
