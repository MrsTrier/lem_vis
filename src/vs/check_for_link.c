/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:20:10 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis_validation.h"
#include "vis_errors.h"

bool		is_valid_objs(char *line, t_input *input)
{
	char	**objs;
	char	*porobably_start;
	char	*porobably_end;
	bool	res;

	res = true;
	objs = ft_strsplit(line, '-');
	porobably_start = objs[0];
	porobably_end = objs[1];
	if (!(room_exists(input->room, porobably_start)) ||
		!(room_exists(input->room, porobably_end)))
		res = false;
	if (!ft_strcmp(porobably_start, porobably_end))
		res = false;
	ft_free_strsplit(objs);
	return (res);
}

t_link		*create_link(t_room *start, t_room *end)
{
	t_link	*link;

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		error_found(ERR_LINK_INIT, NULL);
	link->start = start;
	link->end = end;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

bool		link_exists(t_link *linklst, t_link *new_link)
{
	if (linklst)
	{
		while (linklst->next != NULL)
		{
			if ((linklst->start->name == new_link->start->name &&
				linklst->end->name == new_link->end->name) ||
					(linklst->start->name == new_link->end->name &&
					linklst->end->name == new_link->start->name))
				return (true);
			linklst = linklst->next;
		}
		if ((linklst->start->name == new_link->start->name &&
			linklst->end->name == new_link->end->name) ||
			(linklst->start->name == new_link->end->name &&
			linklst->end->name == new_link->start->name))
			return (true);
	}
	return (false);
}

void		check_for_link(char *input, t_input *data, char ***objs)
{
	t_link	*link;
	t_room	*start;
	t_room	*end;

	static int i;
	i++;

	if (((data->flag & ANT) == ANT) && ((data->flag & ROOMS) == ROOMS)
		&& (data->start_room) && (data->end_room))
	{
		if (!is_valid_objs(input, data))
			error_found(ERR_LINK_WITH_NO_ROOM, NULL);
		else
		{
			*objs = ft_strsplit(input, '-');
			start = find_room(data, (*objs)[0]);
			end = find_room(data, (*objs)[1]);
			link = create_link(start, end);
			if (link_exists(data->link, link))
				error_found(ERR_LINK_DUP, NULL);
			else
				save_link(&(data->link), link);
			data->flag |= LINK;
		}
	}
	else
		error_found(ERR_INPUT, NULL);
}
