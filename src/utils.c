#includ "../include/philo.h"

size_t	ft_strlen(char *str)
{
	size_t i;
	while (str[i] != '\0')
		i++;
	return (i);
}

void put_endl_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	return ;
}

void	put_error(char *str)
{
	ft_putendl_fd(str, 2);
	return ;
}
