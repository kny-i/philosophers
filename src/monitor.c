#include "../include/philo.h"

void	*monitor_routine(void *ptr)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)ptr;
	while (1)
	{
		time_keeper(monitor->data, 1000);
		if (get_time(monitor->data) - monitor->philo->last_eat_time  > monitor->data->time_to_die)
		{
			print_action(monitor->philo, "is die");
			exit(1);
		}
	}
	return (NULL);
}