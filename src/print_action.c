#include "../include/philo.h"

/*size_t	get_time(t_data *data)
{
	struct timeval	tv;
	size_t			time;
	int				ret;

	ret = gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - data->philos[]->start_time;
	return (time);
}*/

size_t	get_time_philo(t_philo *philo)
{
	struct timeval	tv;
	size_t			time;


	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - philo->start_time;
	return (time);
}

int	print_action(t_philo *philo, char *message)
{
	if (philo->data->is_finished == 1)
		return (1);
	printf("%8zu %zu %s\n", get_time_philo(philo), philo->philo_number, message);
	return (0);
}