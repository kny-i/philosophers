#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->has_fork_right == 1 && philo->has_fork_left == 1)
	{
		print_action("is eating");

	}
}