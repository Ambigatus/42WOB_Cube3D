/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:29:17 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/19 16:36:52 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* If we have problem with parser, we clean everything and give back an
** error message  */
void	end_map_parsing(t_system *system, char *msg, char *line)
{
	ft_free_split(system->map);
	free_initialization(system, line);
	exit (error_msg(msg));
}

/* The function takes an integer array info as input and checks if
** all the elements of the array have a value of 1. It does this by iterating
** over the elements of the array and counting the number of elements that have
** a value of 1. If the count is equal to 6 (the length of the array), it
** returns 1, indicating that all elements are set to 1. Otherwise, it returns
** 0, indicating that some elements are not set to 1. */
int	check_info(int *info)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 6)
	{
		if (info[i] == 1)
			count++;
		i++;
	}
	if (count < 6)
		return (0);
	else
		return (1);
}

/* This function takes in a string line and an integer type. It checks if the
** characters in line are either 1 or whitespace until it encounters a
** newline character. If type is 0, it returns 1 if the last character
** before the newline is not whitespace and there was at least one character
** before the newline. If type is 1, it returns 1. Otherwise, it returns 0.
** In summary, this function is used to check if the first line of a file is
** valid according to the rules. */
int	check_lines(char *line, int type)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	if (type == 0 && line[i] == '\n' && i > 0)
		return (1);
	if (type == 1)
		return (1);
	return (0);
}

/* This function reads the input file descriptor line by line using the
** get_next_line function until it finds a valid line that contains characters
** other than space or the number 1. It then continues to read the rest of the
** lines to determine the height of the map. If the height is less than 3,
** it exits with an error message. Finally, it closes the file descriptor. */
void	find_the_height(t_system *system)
{
	char	*line;

	system->height = 0;
	line = ft_strdup("");
	while (line)
	{
		ft_free(line);
		line = get_next_line(system->fd);
		if (line && check_lines(line, 0))
		{
			while (line)
			{
				system->height++;
				ft_free(line);
				line = get_next_line(system->fd);
			}
		}
	}
	close(system->fd);
	system->fd = 0;
	if (system->height < 3)
		exit (error_msg(INVALID_MAP));
}

/* The space_validation function checks the map stored in the system structure
** and adds spaces to each line to make them the same length as the longest
** line in the map. It does this by calling the realloc_set function which
** allocates a new string with a specified length, fills it with a given
** character, copies the contents of the original string into it, and frees
** the old string. If memory allocation fails, the function calls
** end_map_parsing with an appropriate error code. */
void	space_validation(t_system *system)
{
	int	i;

	i = 0;
	while (system->map[i])
	{
		if (ft_strlen(system->map[i]) < system->width)
			system->map[i] = realloc_set(system->map[i], system->width, ' ');
		if (!system->map[i])
			end_map_parsing(system, MALLOC, NULL);
		i++;
	}
}
