#include "../include/philo.h"

void	*philo_test(void *str)
{
	printf("[%s]\n", (char *)str);
	return (NULL);
}

void create_thread(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&(data->philos[i]->thread_philo), NULL, &philo_test, "ASB");
		i++;
	}
}

void	join_thread(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i]->thread_philo, NULL);
		i++;
	}
}