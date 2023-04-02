/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:46:16 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/02 18:23:37 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/*  function compares the first word in a line of text to a given string type.
** If they match, it sets the corresponding value in the system struct to 1.
** If the value is already set to 1, it exits the program with an error 
** message. If the first word in the line of text does not match type,
** the function returns 1. */
int	cmp_setup(t_system *system, char *line, char *type, int val)
{
	char	**split;

	split = ft_split_charset(line, WHITE);
	if (!split)
	{
		free_initialization(system, line);
		exit (error_msg(MALLOC));
	}
	if (!ft_strcmp(split[0], type))
	{
		if (system->info[val] == 0)
			system->info[val] = 1;
		else
		{
			free_initialization(system, line);
			ft_free_split(split);
			exit (error_msg(LOT_OF_SET));
		}
		ft_free_split(split);
		return (0);
	}
	ft_free_split(split);
	return (1);
}
