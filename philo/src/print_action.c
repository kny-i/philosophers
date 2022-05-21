#include "../include/philo.h"

void	print_help(void)
{
	printf("Usage: [number of philosophers]");
	printf("[time to die] [time to eat] [time to sleep]");
	printf(" [number of meals a philosopher has to eat]\n");
	printf("arguments must be zero to INT_MAX\n");
}

int	print_action(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->shared_mutex);
	if (philo->data->is_finished == 1)
	{
		pthread_mutex_unlock(&philo->data->shared_mutex);
		return (1);
	}
	printf("%8zu: %d %s\n", get_time_philo(philo), philo->philo_number, message);
	pthread_mutex_unlock(&philo->data->shared_mutex);
	return (0);
}
