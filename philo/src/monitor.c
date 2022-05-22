#include "../include/philo.h"

static void	monitor_action(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (monitor->data->is_finished != 1)
	{
		if (get_time_philo(monitor->philo) - monitor->philo->last_eat_time \
						> monitor->data->time_to_die)
		{
			print_action(monitor->philo, "died");
			terminate_program(monitor->data);
		}
		if (monitor->philo->eat_count >= monitor->data->number_of_min_eat)
			monitor->is_reached_min_eat = 1;
		while (i < monitor->data->number_of_philo && monitor->data->argc == 6)
		{
			if (monitor->data->monitors[i].is_reached_min_eat == 0)
				break ;
			i++;
			if (i == monitor->data->number_of_philo)
				terminate_program(monitor->data);
		}
	}
}

void	*monitor_routine(void *ptr)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)ptr;
	time_keeper_philo(monitor->philo, monitor->data->time_to_die);
	monitor_action(monitor);
	return (NULL);
}
