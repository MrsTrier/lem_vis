
# include "visualisation.h"

void push_new_room(t_room **roomlst, t_room *room)
{
	t_room **head;
	t_room	*pr;

	pr = *roomlst;
	head = roomlst;
	if (*head)
	{
		while (pr->next != NULL)
			pr = pr->next;
	}
	if (!*head)
	{
		*head = room;
		(*head)->next = NULL;
	}
	else
	{
		pr->next = room;
		pr->next->next = NULL;
	}
}


bool	save_room(t_room *room, t_input *input)
{
	if (!can_i_create(input))
		error_found(ERR_ROOM_INIT);
	else
	{
		if (!(input->flag & ROOMS))
			input->flag |= ROOMS;
		if (input->flag & START)
			input->flag |= START_ROOM;
		if (input->flag & END)
			input->flag |= END_ROOM;
		push_new_room(&(input->room), room);
		printf("=== I saved room with name %s!!! ===\n", room->name);
		printf("=== Pointer is now on room %s!!! ===\n", (input->room)->name);
	}
}