#include "../include/philo.h"

size_t	get_time_philo(t_philo *philo)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - philo->data->start_time;
	return (time);
}

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	time_keeper_philo(t_philo *philo, size_t time)
{
	size_t	start_time;
	size_t	passed_time;

	start_time = get_time_philo(philo);
	while (1)
	{
		passed_time = get_time_philo(philo);
		if (passed_time - start_time >= time)
			return (0);
		pthread_mutex_lock(&philo->data->shared_mutex);
		if (philo->data->is_finished == 1)
		{
			pthread_mutex_unlock(&philo->data->shared_mutex);
			return (1);
		}
		else
			pthread_mutex_unlock(&philo->data->shared_mutex);
		usleep(100);
	}
}
