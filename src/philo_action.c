#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->has_fork_right == 1 && philo->has_fork_left == 1)
	{
		print_action(philo, "is eating");
		philo->last_eat_time = get_time(philo->data);
		time_keeper(philo->data, philo->data->time_to_eat);
		if (philo->philo_number != philo->data->number_of_philo)
		{
			pthread_mutex_unlock(&(philo->data->forks_mutex[philo->philo_number - 1]));
			pthread_mutex_unlock(&(philo->data->forks_mutex[philo->philo_number]));
			philo->has_fork_left = 0;
			philo->has_fork_right = 0;
			philo->eat_count++;
		}
		else
		{
			pthread_mutex_unlock(&(philo->data->forks_mutex[philo->philo_number - 1]));
			pthread_mutex_unlock(&(philo->data->forks_mutex[0]));
			philo->has_fork_left = 0;
			philo->has_fork_right = 0;
			philo->eat_count++;
		}
	}
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	time_keeper(philo->data, philo->data->time_to_sleep);
}
void	philo_think(t_philo *philo)
{
	print_action(philo,"is thinking");
}