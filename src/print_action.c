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

/*int	print_action(t_philo *philo, char *message)
{
	char	*s[5];

	s[0] = "has taken a fork";
	s[1] = "is sleeping";
	s[2] = "is thinking";
	s[3] = "is dead";
	s[4] = "is eating";
	if (philo->data->is_finished == 1)
		return (1);
	pthread_mutex_lock(&(philo->data->shared_mutex));
	if (strcmp(s[0], message) == 0)
		printf("\x1b[33m%8zu: \x1b[37m%d \x1b[36m%s\n", \
		get_time_philo(philo), philo->philo_number, message);
	if (strcmp(s[1], message) == 0)
		printf("\x1b[33m%8zu: \x1b[37m%d \x1b[35m%s\n", \
		get_time_philo(philo), philo->philo_number, message);
	if (strcmp(s[2], message) == 0)
		printf("\x1b[33m%8zu: \x1b[37m%d \x1b[32m%s\n", \
		get_time_philo(philo), philo->philo_number, message);
	if (strcmp(s[3], message) == 0)
		printf("\x1b[33m%8zu: \x1b[37m%d \x1b[31m%s\n", \
		get_time_philo(philo), philo->philo_number, message);
	if (strcmp(s[4], message) == 0)
		printf("\x1b[33m%8zu: \x1b[37m%d \x1b[34m%s\n", \
		get_time_philo(philo), philo->philo_number, message);
	pthread_mutex_unlock(&(philo->data->shared_mutex));
	return (0);
}*/
