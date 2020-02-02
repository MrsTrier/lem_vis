
# include "../includes/visualisation.h"


int		count_objs(char	**objs)
{
	int 	obj_index;

	obj_index = 0;
	while (*objs != NULL)
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
	while (*objs != NULL)
	{
		obj_index++;
		*objs++;
	}
	if (obj_index != 3)
		return (false);
	return (true);
}

bool	is_room(char *line)
{
	char	**objs;
	bool	res;

	res = false;
	objs = ft_strsplit(line, ' ');
	if (!is_only_three(objs))
		res = false;
	else
	{
		if (!(objs[0][0] && objs[0]))//?
			res = false;
		else if (!(objs[1] && is_int(objs[1])))
			res = false;
		else if (!(objs[2] && is_int(objs[2])))
			res = false;
		else
			res = true;
	}
	free_arr(objs);
	free(objs);
	return (res);
}

bool	is_link(char *line)
{
	char	**objs;
	int 	obj_index;
	char	*dash;

	obj_index = 0;
	if (dash = ft_strchr(line, '-'))
	{
		objs = ft_strsplit(line, '-');
		if ((obj_index = count_objs(objs)) != 2)
			return (false);
		return (true);
	}
	return (false);
}

bool	is_ant_num(char *line)
{
	int		ant_num;
	char	*space;

	if (space = ft_strchr(line, ' '))
		return (false);
	ant_num = is_int(line);
	if (ant_num)
		return (true);
	return (false);
}

bool	is_result_row(char *line)
{

}

void	set_flags(char *line, uint8_t *flag)
{
	if (line[2] == 's')
	{
		*flag |= START;
		*flag &= ~START_ROOM;
	}
	else if (line[2] == 'e')
	{
		*flag |= END;
		*flag &= ~END_ROOM;
	}
}

bool	is_type_of_room(char *line, t_input *input)
{
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		return (true);
	return (false);
}

bool	is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (true);
	return (false);
}