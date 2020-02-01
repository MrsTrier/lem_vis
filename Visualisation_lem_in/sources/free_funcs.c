# include "visualisation.h"

void	free_room(t_input *input)
{
	while (input->room != NULL)
	{
		free(input->room->name);
		free(input->room);
		input->room = input->room->next;
	}
//	free_arr(rooms_lst);
//	free(rooms_lst);
}