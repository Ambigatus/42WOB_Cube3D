/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:46:16 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/03 18:55:20 by ddzuba           ###   ########.fr       */
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

/* This function takes a system structure and a line of text as input. It splits
** the line into substrings using whitespace as a delimiter and stores the
** substrings in an array. It then checks the number of substrings in the array
** and exits with an error message if there are more than two. If there are no
** errors, it returns the array of substrings. If there is an error, it frees
** the allocated memory and exits the program. */
char	**split_and_validate_line(t_system *system, char *line)
{
	char	**splitted;
	int		i;

	splitted = ft_split_charset(line, WHITE);
	if (!splitted)
	{
		free_initialization(system, line);
		exit (error_msg(MALLOC));
	}
	i = 0;
	while (splitted[i])
		i++;
	if (i > 2)
	{
		free_initialization(system, line);
		ft_free(splitted);
		exit (error_msg(INVALID_SET));
	}
	return (splitted);
}
