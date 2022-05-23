#include "../include/philo.h"

int	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->shared_mutex);
	if (philo->data->is_finished == 1)
	{
		pthread_mutex_unlock(&philo->data->shared_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->shared_mutex);
	if (print_action(philo, "is sleeping") == 1)
		return (1);
	if (time_keeper_philo(philo, philo->data->time_to_sleep) == 1)
		return (1);
	return (0);
}

int	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->shared_mutex);
	if (philo->data->is_finished == 1)
	{
		pthread_mutex_unlock(&philo->data->shared_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->shared_mutex);
	if (print_action(philo, "is thinking") == 1)
		return (1);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if ((philo->philo_number % 2) == 0)
		usleep(200);
	while (philo->data->is_finished != 1)
	{
		if (pickup_fork(philo) == 1)
			break ;
		if (philo_eat(philo) == 1)
			break ;
		if (philo_sleep(philo) == 1)
			break ;
		if (philo_think(philo) == 1)
			break ;
	}
	put_down_fork(philo);
	return (NULL);
}
