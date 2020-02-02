# include "visualisation.h"

void	free_room(t_input *input)
{
	while (input->room != NULL)
	{
		free(input->room->name);
		free(input->room);
		input->room = input->room->next;
	}
}


void	free_rooms(t_input *input)
{
	free_room(input);
}
