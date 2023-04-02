/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:08:33 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/02 20:38:06 by ddzuba           ###   ########.fr       */
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
