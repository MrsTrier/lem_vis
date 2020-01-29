
# include "../includes/visualisation.h"


int		count_objs(char	**objs)
{
	int 	obj_index;

	obj_index = 0;
	while (objs != NULL)
	{
		obj_index++;
		*objs++;
	}
	return (obj_index);
}

bool	is_only_three(char	**objs)
{
	int 	obj_index;

	obj_index = 0;
	while (objs != NULL && obj_index < 4)
	{
		obj_index++;
		*objs++;
	}
	if (objs != NULL || obj_index != 3)
		return (false);
	return (true);
}

bool	is_room(char *line)
{
	char	**objs;
	int 	obj_index;

	obj_index = 0;
	objs = ft_strsplit(line, ' ');
	if (!is_only_three(objs))
		return (false);
	else
	{
		if (!(objs[0][0] && objs[0]))//?
			return (false);
		if (!(objs[1] && is_int(objs[1])))
			return (false);
		if (!(objs[2] && is_int(objs[2])))
			return (false);
		return (true);
	}
}

bool	is_link(char *line)
{
	char	**objs;
	int 	obj_index;

	obj_index = 0;
	objs = ft_strsplit(line, '-');
	if ((obj_index = count_objs(objs)) != 2)
		return (false);
	return (true);
}

bool	is_ant_num(char *line)
{
	int ant_num;

	ant_num = ft_atoi(line);
	if (ant_num >= 0)
		return (true);
	return (false);
}

bool	is_result_row(char *line)
{

}

bool	is_type_of_room(char *line, t_input *input)
{
	if (!ft_strcmp(line, "##start"))
	{
		input->flag |= START;
		input->flag &= ~START_ROOM;
		return (true);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		input->flag |= END;
		input->flag &= ~END_ROOM;
		return (true);
	}
	return (true);
}

bool	is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (true);
	return (false);
}