#include "../include/philo.h"

void	*monitor_routine(void *ptr)
{
	t_monitor	*monitor;
	int			i;

	monitor = (t_monitor *)ptr;
	i = 0;
	time_keeper(monitor->data, monitor->data->time_to_die);
	while (monitor->data->is_finished != 1)
	{
		if (get_time(monitor->data) - monitor->philo->last_eat_time  > monitor->data->time_to_die )
		{
			print_action(monitor->philo, "is die");
			terminate_program(monitor->data);
		}
		if (monitor->philo->eat_count >= monitor->data->number_of_min_eat)
			monitor->is_reached_min_eat = 1;
		while(i < monitor->data->number_of_philo && monitor->data->argc == 6)
		{
			if (monitor->data->monitors[i]->is_reached_min_eat == 0)
				break ;
			i++;
			if (i == monitor->data->number_of_philo)
				terminate_program(monitor->data);
		}
	}
	return (NULL);
}