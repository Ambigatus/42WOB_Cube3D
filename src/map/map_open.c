/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:08:33 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/03 18:45:25 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* 1. Allocate memory for the map based on the given height in the system
struct.
* 2. Loop through each line of the map, copying it to the system struct's map
and removing any trailing newline characters.
* 3. Free the memory used by the current line and read the next line using
get_next_line.
* 4. When all lines have been processed, terminate the map with a null 
terminator and close the file descriptor.
* 5. Return a pointer to the last line read by get_next_line. */
char	*open_map(t_system *system, char *line)
{
	size_t	i;

	i = 0;
	system->map = malloc(sizeof(char *) * (system->height + 1));
	if (!system->map)
	{
		free_initialization(system, line);
		exit (error_msg(MALLOC));
	}
	while (line && i <= system->height)
	{
		system->map[i] = ft_strdup(line);
		if (system->map[i][ft_strlen(system->map[i]) - 1] == '\n')
			system->map[i][ft_strlen(system->map[i]) - 1] = '\0';
		if (!system->map[i])
			end_map_parsing(system, MALLOC, line);
		ft_free(line);
		line = get_next_line(system->fd);
		i++;
	}
	system->map[i] = 0;
	close(system->fd);
	system->fd = 0;
	return (line);
}

/*** It first checks if the line contains a valid number of values, according to
the game's rules. If it's not valid, it frees the initialization and exits
the program with an error message.
** If the line is valid, it checks if all the necessary information in t_system
has been filled. If not, it frees the initialization and exits the program with 
an error message.
** If both checks pass, it opens the map and checks if the map contains only 
valid characters (i.e., '0', '1', '2', 'N', 'S', 'E', 'W', or ' '). 
If any other character is found, it exits the program with an error message.
** It then checks if the last line of the map contains only valid characters, 
as per the game rules. If it doesn't, it exits the program with an error message.
** It then calls the walls_validation and space_validation functions to validate 
that the walls are properly placed and that there is only one space character 
between the wall and the rest of the map, respectively.
** Finally, it returns the line string. */
char	*map_validation(t_system *system, char *line)
{
	if (!check_lines(line, 0))
	{
		free_initialization(system, line);
		exit (error_msg(INVALID_SET));
	}
	else
	{
		if (!check_info(system->info))
		{
			free_initialization(system, line);
			exit (error_msg(MISSING));
		}
		line = open_map(system, line);
		only_valid_char(system);
		if (!check_lines(system->map[system->height - 1], 1))
			end_map_parsing(system, INVALID_MAP, line);
		walls_validation(system);
		space_validation(system);
	}
	return (line);
}

/* Maybe here we need to add validate_space_around function. Maybe not. */