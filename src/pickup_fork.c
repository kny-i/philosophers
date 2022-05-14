#include "../include/philo.h"

void	pickup_fork(t_philo *philo)
{
	if (philo->has_fork_right == 0)
	{
		pthread_mutex_lock(&(philo->data->forks_mutex[philo->philo_number - 1]));
		philo->has_fork_right = 1;
		print_action(philo, "has taken a fork");
	}
	if (philo->has_fork_left == 0)
	{
		if (philo->philo_number != philo->data->number_of_philo)
		{
			pthread_mutex_lock(&(philo->data->forks_mutex[philo->philo_number]));
			philo->has_fork_left = 1;
			print_action(philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&(philo->data->forks_mutex[0]));
			philo->has_fork_left = 1;
			print_action(philo, "has taken a fork");
		}
	}

}