#ifndef VISUALISATION_H
# define VISUALISATION_H


const int SCREEN_WIDTH = 1940;
const int SCREEN_HEIGHT = 1080;

# define ANT (1 << 0)
# define ROOMS (1 << 1)
# define START (1 << 2)
# define END (1 << 3)
# define LINK (1 << 4)
# define START_ROOM (1 << 5)
# define END_ROOM (1 << 6)


# include "../libft/includes/libft.h"
# include <stdbool.h>

//
//typedef struct		s_vsual_tools
//{
//	SDL_Window		*window;
//	SDL_Renderer	*renderer;
//	TTF_Font		*font;
//	SDL_Texture		*bg;
//	SDL_Rect		*bg_dims;
//	SDL_Texture		*lem_in;
//	SDL_Texture		*room_start_end;
//	SDL_Texture		*room_middle;
//	SDL_Texture		*ant;
//	SDL_Texture		*press_space;
//	SDL_Texture		*reload;
//	SDL_Texture		*next;
//	t_bool			welcome;
//	t_bool			close;
//	t_bool			ants_is_moving;
//	int				x_shift;
//	int				y_shift;
//}					t_vsual_tools;
//


typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
//	t_type				type;
//	int					bfs_level;
	int					input_links;
	int					output_links;
	int					ant_number;
	struct s_room		*next;
}						t_room;


typedef struct			s_link
{
	t_room				*start;
	t_room				*end;
	struct s_link		*next;
	struct s_link		*prev;
}						t_link;


typedef struct		s_input
{
	int				ants_num;
	int				rooms_num;
	t_room			*room;
	t_link			*link;
	char			*start_room;
	char 			*end_room;
	uint8_t			flag;
	t_room			*pr;

}					t_input;

bool	is_room(char *line);
bool	is_link(char *line);
bool	is_ant_num(char *line);
bool	is_result_row(char *line);
bool	is_type_of_room(char *line, t_input *input);
bool	is_comment(char *line);


typedef struct			s_sizes
{
	int					room_hight;
	int					room_width;
	int					space_w;
	int					space_h;
	int					bounds;
}						t_sizes;

typedef struct			s_ant
{
	int					index;
	t_room				*start;
	t_room				*end;
	struct s_ant		*next;
}						t_ant;



typedef struct		s_stack
{
//	t_bool			a_is_full;
	int				max;
	int				min;
	int				mdn;
	int				length;
	int				best;
	int				place;
	char			**cmnd;
	char			**pr;
	char			**first_elem;
	unsigned		flag;

}					t_stack;



void	free_room(t_input *input);
void	free_rooms(t_input *input);
void	error_found(char *s);
void	set_flags(char *line, uint8_t *flag);
bool	save_room(t_room *room, t_input *input);

#endif