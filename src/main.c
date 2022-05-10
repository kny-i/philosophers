#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 5 || argc != 6)
		put_error("invalid arguments");
	init_data(&data, argc, argv);
}

