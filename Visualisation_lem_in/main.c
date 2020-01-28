

#include "visualisation.h"

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

//
//int		main(int ac, char **av)
//{
//
//	process_input();
//	animate_our_sollution();
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

void	create_room(t_room *room, t_input *input)
{
	room = (t_room *)malloc(sizeof(t_room));
	room->next = NULL;
	room->name = "";
	room->x = 0;
	room->y = 0;
	room->ant_number = 0;
	room->input_links = 0;
	room->output_links = 0;
}

void	parse_input(t_input *input)
{
	input->room
}

int		main(int ac, char **av)
{
	t_input 	input;
	t_room		room;


	parse_input(&input);
	create_room(&room, &input);
	try_functions();
}