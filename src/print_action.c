#include "../include/philo.h"

size_t	get_time(t_data *data)
{
	struct timeval	tv;
	size_t			time;
	int				ret;

	ret = gettimeofday(&tv, NULL);
//	if (ret == -1)
//		free_all_elem(data);
	// printf("tv_sec = %ld tv_usec = %06d\n", tv.tv_sec, tv.tv_usec);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	print_action(t_philo *philo, char *message)
{
	printf("%zu %zu %s\n", get_time(philo->data), philo->philo_number, message);
}