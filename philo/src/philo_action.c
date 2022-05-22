#include "../include/philo.h"

static void	philo_eat_fin(t_philo *philo)
{
//	pthread_mutex_lock(&philo->data->shared_mutex);
	philo->has_fork_left = 0;
	philo->has_fork_right = 0;
	philo->eat_count++;
//	pthread_mutex_unlock(&philo->data->shared_mutex);
}

int	philo_eat(t_philo *philo)
{
	if (philo->data->is_finished == 1)
		return (1);
	if (philo->has_fork_right == 1 && philo->has_fork_left == 1)
	{
		if (print_action(philo, "is eating") == 1)
			return (1);
		philo->last_eat_time = get_time_philo(philo);
		if (time_keeper_philo(philo, philo->data->time_to_eat) == 1)
			return (1);
		if (philo->philo_number != philo->data->number_of_philo)
		{
			pthread_mutex_unlock \
			(&(philo->data->forks_mutex[philo->philo_number - 1]));
			pthread_mutex_unlock \
			(&(philo->data->forks_mutex[philo->philo_number]));
		}
		else
		{
			pthread_mutex_unlock \
			(&(philo->data->forks_mutex[philo->philo_number - 1]));
			pthread_mutex_unlock(&(philo->data->forks_mutex[0]));
		}
		philo_eat_fin(philo);
	}
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (philo->data->is_finished == 1)
		return (1);
	if (print_action(philo, "is sleeping") == 1)
		return (1);
	if (time_keeper_philo(philo, philo->data->time_to_sleep) == 1)
		return (1);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (philo->data->is_finished == 1)
		return (1);
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
		if (pickup_fork(philo) == 1 || philo_eat(philo) == 1 || \
		philo_sleep(philo) == 1 || philo_think(philo) == 1 \
				|| philo->data->is_finished == 1)
			break ;
	}
	put_down_fork(philo);
	return (NULL);
}
