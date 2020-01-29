

#include "../includes/visualisation.h"

#include <stdio.h>


const int SCREEN_WIDTH = 1940;
const int SCREEN_HEIGHT = 1080;

void	keep_w_to_h_ratio(t_sizes *sizes)
{
	bool status;
	double ratio;

	status = false;
	ratio = (double)sizes->room_hight / sizes->room_width;
	while (ratio > 0.8)
	{
		sizes->room_hight -= 1;
		ratio = (double)sizes->room_hight / sizes->room_width;
	}
	while (ratio < 0.8)
	{
		sizes->room_width -= 1;
		ratio = (double)sizes->room_hight / sizes->room_width;
	}
	printf("width: %d\nhight: %d\n", sizes->room_width, sizes->room_hight);

}

void	convert_coords(t_sizes *sizes, t_room *room)
{
	int multiplier_x;
	int multiplier_y;


	printf("x: %d\ny: %d\n", room->x, room->y);
	multiplier_x = (room->x < 0 ? (room->x * (-1)) : room->x);
	if (!room->x)
		multiplier_x = 0;
	multiplier_y = (room->y < 0 ? (room->y * (-1)) : room->y);
	if (!room->y)
		multiplier_y = 0;
	room->x = sizes->space_w * multiplier_x + sizes->bounds + sizes->room_width * multiplier_x;
	room->y = sizes->space_h * multiplier_y + sizes->bounds + sizes->room_hight * multiplier_y;
	printf("x: %d\ny: %d\n", room->x, room->y);
}

void	calc_rooms_size(int max_x, int max_y, t_sizes *sizes)
{
	int free_space_w;
	int free_space_h;

	free_space_w = 0;
	free_space_w = 0;
	sizes->bounds = 150;
	free_space_w = SCREEN_WIDTH - ((SCREEN_WIDTH - sizes->bounds * 2) / 3);
	sizes->space_w = ((SCREEN_WIDTH - sizes->bounds * 2) / 3 ) / (max_x - 1);
	sizes->room_width = free_space_w / max_x;
	free_space_h = SCREEN_HEIGHT - ((SCREEN_HEIGHT - sizes->bounds * 2) / 3);
	sizes->space_h = ((SCREEN_HEIGHT - sizes->bounds * 2) / 3 ) / (max_y - 1);
	sizes->room_hight = free_space_h / max_y;
	keep_w_to_h_ratio(sizes);
}

//
//void 	process_input()
//{
//	save_number_of_ants();
//	save_the_rooms();
//	save_the_links();
//	save_ants_trecks();
//}

void	try_functions()
{
	t_sizes	sizes;
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	room->y = 0;
	room->x = 4;
	room->name = "1";
	calc_rooms_size(5, 7, &sizes);
	convert_coords(&sizes, room);
}

bool	can_i_create(t_input *input)
{
	if (input->flag & ANT)
		return true;
	return false;
}

bool	save_room(t_room *room, t_input *input)
{
	if (!can_i_create(input))
		return NULL;
	else
	{
		if (input->flag & ROOMS)
			input->flag |= ROOMS;
		if (input->flag & START)
			input->flag |= START_ROOM;
		if (input->flag & END)
			input->flag |= END_ROOM;
		if (input->room != NULL)
			input->room = input->room->next;
		input->room = room;
	}
	//ERROR
}


t_room		*create_room(t_input *input, char *line)
{
	char	*name;
	int		x;
	int 	y;
	t_room	*room;

	if (!can_i_create(input))
		return NULL;
	room = (t_room *)malloc(sizeof(t_room));
	room->next = NULL;
	room->name = "";
	room->x = 0;
	room->y = 0;
	room->ant_number = 0;
	room->input_links = 0;
	room->output_links = 0;
	return (room);
}

bool	is_free_line(char *line)
{
	if (!ft_strcmp(line, "\n"))
		return false;
	return true;
}

void	save_number_of_ants(t_input *input, int ant_num)
{
	if (!can_i_create(input))
	{
		input->flag |= ANT;
		input->ants_num = ant_num;
	}
	//ERROR
}


int		parse_input(t_input *input)
{
	char		*line;
	int 		line_index;

	line_index = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!*line)
			break ;
		if (is_ant_num(line) || is_room(line) || is_link(line) || is_result_row(line) ||
							is_type_of_room(line, input) || is_comment(line))
		{
			if (is_ant_num(line))
				save_number_of_ants(input, ft_atoi(line));
			else if (is_room(line)) //Узнать тонкости валидации ввода
				save_room(create_room(input, line), input);
			else if (is_comment(line))
				;
			else if (is_type_of_room(line, input))
				;
			else if (is_link(line))
				;
			else
				//Error
			line_index += 1;
		}
		free(line);
	}
	return (1);
}

void	initialize_vars(t_input *input)
{
	input->ants_num = -1;
	input->rooms_num = -1;
	input->start_room = -1;
	input->end_room = -1;
	input->flag = 0b01100000;
}

int		main(int ac, char **av)
{
	t_input 	input;
	t_room		room;

	initialize_vars(&input);
	parse_input(&input);
	//	animate_our_sollution();
}