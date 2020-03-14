/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:59 by mcanhand          #+#    #+#             */
/*   Updated: 2020/02/25 13:22:09 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"
#include "vis_validation.h"
#include "vis_errors.h"
#include <stdio.h>

void			check_params(char *ant_room, t_input *data)
{
	char		**objs;

	objs = ft_strsplit(ant_room, '-');
	if (!is_int(objs[0]))
		error_found(ERR_INPUT, NULL);
	if (ft_atoi(objs[0]) > data->ants_num)
		error_found(ERR_INPUT, NULL);
	if (!room_exists(data->room, objs[1]))
		error_found(ERR_INPUT, NULL);
	ft_free_strsplit(objs);
}

void			is_res_right(char *res, t_input *data)
{
	char		**objs;
	char		*ant_room;
	int			i;

	i = 0;
	objs = ft_strsplit(res, ' ');
	while (objs[i] != NULL)
	{
		ant_room = (objs[i] + 1);
		if (objs[i][0] != 'L')
			error_found(ERR_INPUT, NULL);
		check_params(ant_room, data);
		i++;
	}
	ft_free_strsplit(objs);
}

void			validate_result(char *res, t_input *data)
{
	char		**objs;
	int			i;
	t_iteration	*iter;

	i = 0;
	objs = ft_strsplit(res, '\n');
	if (objs)
	{
		while (objs[i] != NULL)
		{
			if (!ft_strchr(objs[i], 'L') || !ft_strchr(objs[i], '-'))
				error_found("ERROR: lem-in result contains error", NULL);
			is_res_right(objs[i], data);
			iter = create_iteration(data, objs[i]);
			save_iteration(&(data->iteration), iter);
			data->iter_num += 1;
			i++;
		}
	}
	ft_free_strsplit(objs);
}
