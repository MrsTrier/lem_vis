/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_objtype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:37:34 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"

bool	is_room(char *line)
{
	char	**objs;
	bool	res;
	int		objs_num;

	res = false;
	objs = ft_strsplit(line, ' ');
	objs_num = count_objs(objs);
	if (objs_num != 3 || ft_strchr(objs[0], '-') || ft_strchr(objs[0], '#'))
		res = false;
	else
	{
		if (!objs[0][0] || !objs[0] || objs[0][0] == 'L')
			res = false;
		else if (!(objs[1] && is_int(objs[1])))
			res = false;
		else if (!(objs[2] && is_int(objs[2])))
			res = false;
		else
			res = true;
	}
	ft_free_strsplit(objs);
	return (res);
}

bool	is_link(char *line)
{
	char	**objs;
	bool	res;

	res = false;
	if (ft_strchr(line, '-'))
	{
		objs = ft_strsplit(line, '-');
		if (count_objs(objs) == 2)
			res = true;
		ft_free_strsplit(objs);
	}
	return (res);
}

bool	is_ant_num(char *line)
{
	int		ant_num;

	if (ft_strchr(line, ' '))
		return (false);
	ant_num = is_int(line);
	if (ant_num)
		if (ant_num > 0)
			return (true);
	return (false);
}

bool	is_type_of_room(char *line)
{
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		return (true);
	return (false);
}

bool	is_comment(char *line)
{
	if (line[0] == '#' && !ft_strequ((const char *) (line + 1), "#start") &&
		!ft_strequ((const char *) (line + 1), "#end"))
		return (true);
	return (false);
}
