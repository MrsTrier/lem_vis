# include "visualisation.h"
#include <errno.h>

void	putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

void	error_found(char *s)
{
	if (errno == 0)
		putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}
