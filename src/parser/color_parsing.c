/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:57:24 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/26 17:46:12 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* Just small helping function for error managment */
static void	exit_error_msg(int type)
{
	if (type == CEILING)
		exit (error_msg(RGB_C));
	else
		exit (error_msg(RGB_F));
}

/* This is a static function called "rgb_split" that takes in a pointer to a
** t_system struct, a string "line" and an integer "type" as input parameters.
** The purpose of the function is to split the string "line" into an array of
** strings using "," as the separator and return the resulting array of strings.
** The function performs some validation on the resulting array of strings,
** checking that it contains exactly 3 elements and that the last element is not
** a newline character. If the validation fails, the function frees memory
** allocated by the function and calls the function "exit_error_msg" with the
** input parameter "type" to terminate the program. */
static char	**rgb_split(t_system *system, char *line, int type)
{
	char	**rgb;
	int		i;

	rgb = ft_split_charset(line + 1, ",");
	i = 0;
	if (!rgb)
	{
		free_initialization(system, line);
		exit (error_msg(MALLOC));
	}
	while (rgb[i])
		i++;
	if (i != 3 || rgb[2][0] == '\n')
	{
		free_initialization(system, line);
		ft_free_split(rgb);
		exit_error_msg(type);
	}
	return (rgb);
}

/* This function takes an array of three strings, which are the RGB values of a
** color in decimal format. It converts each RGB value to hexadecimal format and
** concatenates them to form a single 24-bit hexadecimal value representing the
** color. The red value is shifted left by 16 bits, the green value is shifted
** left by 8 bits, and the blue value is placed directly in the resulting
** hexadecimal value. The function returns this hexadecimal value. */
static int	get_hexa(char **rgb)
{
	int	hexa;

	hexa = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	return (hexa);
}

/* Converting RGB color values to a single integer value
(usually in hexadecimal format) can be useful in graphics programming and other
applications where a single value representing a color is required. By combining
the individual red, green, and blue values into a single integer, it becomes 
easier to work with and compare colors.

For example, if you have two colors represented as RGB values and you want to
compare them to see if they are the same, it is much easier to compare their 
single integer representations rather than comparing their individual RGB 
values. */

/* The color_parsing function is responsible for parsing and validating a color
** value from a given line of input. It first splits the line into an array of
** strings representing the red, green, and blue values. Then it checks each
** value to ensure that it is within the valid range of 0 to 255. If any value
** is outside that range, it exits the program with an error message. Finally,
** it converts the three values into a single hexadecimal value using the
** get_hexa function and stores it in the system struct's color array for the
** given type. */
void	color_parsing(t_system *system, char *line, int type)
{
	char	**rgb;
	int		i;
	int		num;

	rgb = rgb_split(system, line, type);
	if (!rgb)
		exit (error_msg(MALLOC));
	i = 0;
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
		{
			free_initialization(system, line);
			ft_free_split(rgb);
			exit_error_msg(type);
		}
		else
			system->color[type] = get_hexa(rgb);
		i++;
	}
	ft_free_split(rgb);
}
