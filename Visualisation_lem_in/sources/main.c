

# include "../includes/visualisation.h"
# include "errors.h"
# include <stdio.h>


bool		can_i_create(t_input *input)
{
	if (input->flag & ANT)
		return true;
	return false;
}

t_room		*create_room(t_input *input, char *line)
{
	t_room	*room;
	char	**objs;

	if (!can_i_create(input))
		return NULL;
	objs = ft_strsplit(line, ' ');
	room = (t_room *)malloc(sizeof(t_room));
	room->next = NULL;
	room->name = ft_strdup(objs[0]);
	room->x = ft_atoi(objs[1]);
	room->y = ft_atoi(objs[2]);
	room->ant_number = 0;
	room->input_links = 0;
	room->output_links = 0;
	free_arr(objs);
	free(objs);
	return (room);
}

void		save_number_of_ants(t_input *input, int ant_num)
{
	if (!can_i_create(input))
	{
		input->flag |= ANT;
		input->ants_num = ant_num;
		printf("\n%s\n", "=== I know how many ants!!! ===");
	}
	else
		error_found(ERR_ANT_INIT);
}

bool		check_if_room_exists(t_room *roomlst, char *name)
{
	if (roomlst)
	{
		while (roomlst->next != NULL)
		{
			if (!(ft_strcmp(roomlst->name, name)))
				return (true);
			roomlst = roomlst->next;
		}
	}
	return (false);
}

t_link		*create_link(t_room *start, t_room *end)
{
	t_link *link;
	t_link	*next;
	t_link	*prev;

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		error_found(ERR_LINK_INIT);
	link->start = start;
	link->end = end;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}


t_room	*find_room(t_input *input, char *name)
{
	t_room	*current;

	current = input->room;
	while (current)
	{
		if (!ft_strcmp(current->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

//t_room		return_start(t_room *room)
//{
//
//	return ;
//}

void		save_link(t_input *input, char *line)
{
	char	**objs;
	t_room	*start;
	t_room	*end;

	objs = ft_strsplit(line, '-');
	if (!(check_if_room_exists(input->room , objs[0])) ||
					!(check_if_room_exists(input->room , objs[1])))
		error_found(ERR_LINK_INIT);
	if ((start = find_room(input, objs[0]) == NULL) ||
								(end = find_room(input, objs[1]) == NULL))
		error_found(ERR_LINK_INIT);
	input->link = create_link(start, end);
	free_arr(objs);
	free(objs);
}

int			parse_input(t_input *input)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!*line)
			break ;
		if (is_ant_num(line) || is_room(line) || is_link(line) || is_result_row(line) ||
							is_type_of_room(line, input) || is_comment(line))
		{
			if (is_ant_num(line))
				save_number_of_ants(input, ft_atoi(line));
			else if (is_room(line))
				save_room(create_room(input, line), input);
			else if (is_comment(line))
				;
			else if (is_type_of_room(line, input))
				set_flags(line, &(input->flag));
			else if (is_link(line))
				save_link(input, line);
			else
				error_found(ERR_READING);
		}
		free(line);
	}
	return (1);
}

void		initialize_vars(t_input *input)
{
	input->ants_num = -1;
	input->rooms_num = -1;
	input->start_room = -1;
	input->end_room = -1;
	input->flag = 0b01100000;
	input->room = NULL;
	input->pr = (input->room);
}


int			main(int ac, char **av)
{
	t_input input;
	t_room	room;

	initialize_vars(&input);
	parse_input(&input);
	free_rooms(&input);
	//	animate_our_sollution();
}