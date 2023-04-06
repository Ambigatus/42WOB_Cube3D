/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:37:22 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/06 21:06:29 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* This function is responsible for validating the settings in a configuration
** file for a programm. It calls the texture_parsing function for texture
** settings (NO, SO, WE, EA, FLOOR, CEILING), and map_validation for map
** settings. It returns a pointer to the current line being parsed, which can be
** used to track the current line number in the file. */
static char	*validate_settings(t_system *system, char *line)
{
	if (!cmp_setup(system, line, "NO", 0))
		texture_parsing(system, line, NO);
	else if (!cmp_setup(system, line, "SO", 1))
		texture_parsing(system, line, SO);
	else if (!cmp_setup(system, line, "WE", 2))
		texture_parsing(system, line, WE);
	else if (!cmp_setup(system, line, "EA", 3))
		texture_parsing(system, line, EA);
	else if (!cmp_setup(system, line, "F", 4))
		texture_parsing(system, line, FLOOR);
	else if (!cmp_setup(system, line, "C", 5))
		texture_parsing(system, line, CEILING);
	else
		line = map_validation(system, line);
	return (line);
}

/* It first checks if the line is empty or contains only white space, and if so,
** it returns the line. If the line is not empty, it passes the line to the
** validate_settings function to determine if it contains a valid setting, such
** as a texture or color. The function then returns the original line or the
** modified line, depending on whether it contains a valid setting or not. */
static char	*check_the_line(char *line, t_system *system)
{
	if (ft_if_empty_line(line))
		return (line);
	else
		line = validate_settings(system, line);
	return (line);
}

/* Validates the input data by reading lines from a file descriptor and checking
** the validity of each line. It calls check_the_line function to validate each
** line and terminates when there are no more lines to read or if the input data
** is incomplete. If the input data is incomplete, it prints an error message
** and exits with failure status. */
static void	validate_data(t_system *system)
{
	char	*line;

	initialization(system);
	line = ft_strdup("");
	while (line && system)
	{
		ft_free(line);
		line = get_next_line(system->fd);
		if (!line && !check_info(system->info))
		{
			free_initialization(system, line);
			error_msg(MISSING);
			exit (EXIT_FAILURE);
		}
		else if (!line)
		{
			ft_free(system->info);
			close(system->fd);
			return ;
		}
		line = check_the_line(line, system);
	}
	ft_free(line);
}

/* Main parser. This function checks the number of arguments passed and the file
** format, gets the file descriptor, finds the height of the map, validates the
** data in the file, and sets the values for the map and mini size in the
** system structure. */
void	parsing(int argc, char **argv, t_system *system)
{
	if (argc != 2)
		exit (error_msg(ARG));
	if (!ft_memcpm_reverse(argv[1], ".cub"))
		exit (error_msg(FORMAT));
	get_fd(system, argv[1]);
	find_the_height(system);
	get_fd(system, argv[1]);
	validate_data(system);
	system->map_s = 64;
	system->mini_s = 32;
}
