# include "stdio.h"

void	free_arr(char **arr)
{
	while (*arr != NULL)
	{
		free(*arr);
		(arr)++;
	}
}
