#include "../include/philo.h"

int	time_keeper_philo(t_philo *philo, size_t time)
{
	size_t	start_time;
	size_t	passed_time;

	start_time = get_time_philo(philo);
	while (1)
	{
		passed_time = get_time_philo(philo);
		if (passed_time - start_time >= time)
			return (0) ;
		if (philo->data->is_finished == 1)
			return (1);
		usleep(100);
	}
	return (0);
}

void	*philo_routine(void *ptr)
{

	t_philo *philo;

	philo = (t_philo *)ptr;
	if ((philo->philo_number % 2) == 0)
		usleep(200);
	while(philo->data->is_finished != 1)
	{
		if ( pickup_fork(philo) == 1 || philo_eat(philo) == 1 || \
		philo_sleep(philo) == 1 || philo_think(philo) == 1 || philo->data->is_finished == 1)
			break ;
	}
	//fork離す関数必要。
	put_down_fork(philo);
//	printf("\x1b[36m[%s philo_num = %zu]\n\033[m", "routine fin", philo->philo_number);
	return (NULL);
}

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time(data->philos);
	while (i < data->number_of_philo)
	{
		pthread_create(&(data->philos[i].thread_philo), NULL, &philo_routine, &data->philos[i]);
		pthread_create(&(data->monitors[i]).thread_monitor, NULL, &monitor_routine, &data->monitors[i]);
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