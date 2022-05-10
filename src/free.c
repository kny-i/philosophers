#include "../include/philo.h"

static void	free_double_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all_elem(t_data *data)
{
	if (data->philos != NULL)
		free_double_array((void **)data->philos);
	if (data->monitors != NULL)
		free_double_array((void **)data->monitors);
	if (data->forks_mutex != NULL)
		free(data->forks_mutex);
	exit(1);//これまずいお♡
}