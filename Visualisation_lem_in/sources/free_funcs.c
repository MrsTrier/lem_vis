# include "visualisation.h"

void	free_room(t_input *input)
{
	while (input->pr != NULL)
	{
		free(input->pr->name);
		free(input->pr);
		input->pr = input->pr->next;
	}
//	free_arr(rooms_lst);
//	free(rooms_lst);
}