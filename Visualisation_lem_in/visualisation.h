#ifndef VISUALISATION_H
# define VISUALISATION_H

# include "libft/includes/libft.h"
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
}					t_input;

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

#endif