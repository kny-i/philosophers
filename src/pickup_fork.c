#include "../include/philo.h"

void	pickup_fork(t_philo *philos)
{
	if (philos->has_fork_right == 0)
	{
		pthread_mutex_lock(&(philos->data->forks_mutex[philos->philo_number]));
		philos->has_fork_right = 1;
		print_action(philos, "has taken a fork");
	}
	if (philos->has_fork_left == 0)
	{
		if (philos->philo_number != philos->data->number_of_philo - 1)
		{
			pthread_mutex_lock(&(philos->data->forks_mutex[philos->philo_number + 1]));
			philos->has_fork_left = 1;
			print_action(philos, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&(philos->data->forks_mutex[0]));
			philos->has_fork_left = 1;
			print_action(philos, "has taken a fork");
		}
	}

}