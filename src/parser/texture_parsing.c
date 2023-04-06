/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:53:36 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/06 20:35:42 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/* Just small error handle function */
static void	internal_error_msg(int type)
{
	char	*msg;

	if (type == NO)
		msg = ft_strdup(PATH_NO);
	else if (type == SO)
		msg = ft_strdup(PATH_SO);
	else if (type == WE)
		msg = ft_strdup(PATH_WE);
	else
		msg = ft_strdup(PATH_EA);
	error_msg(msg);
	ft_free(msg);
}

/* Exist only cuz norminette. Set the texture path and frees after setting */
static void	set_texture_path(t_system *system, char *path, int type)
{
	char	*texture;

	texture = NULL;
	if (type == NO)
	{
		texture = system->texture[NO];
		system->texture[NO] = ft_strdup(path);
	}
	else if (type == SO)
	{
		texture = system->texture[SO];
		system->texture[SO] = ft_strdup(path);
	}
	else if (type == WE)
	{
		texture = system->texture[WE];
		system->texture[WE] = ft_strdup(path);
	}
	else if (type == EA)
	{
		texture = system->texture[EA];
		system->texture[EA] = ft_strdup(path);
	}
	if (texture)
		free(texture);
}

/* This function is responsible for parsing the texture path from the given
** line, storing it in the appropriate field of the system struct, and
** validating the path. It first splits the line and checks if the path ends
** with a newline character. Then it calls the function set_texture_path to
** store the path in the system struct. Finally, it checks if the path is valid
** by checking if it ends with ".xpm". If the path is not valid, it frees memory
** and displays an error message before exiting. */
void	texture_parsing(t_system *system, char *line, int type)
{
	char	**split;
	char	*path;

	split = split_and_validate_line(system, line);
	path = ft_strdup(split[1]);
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = '\0';
	set_texture_path(system, path, type);
	if (!path || !ft_memcpm_reverse(path, ".xpm"))
	{
		free_initialization(system, line);
		ft_free_split(split);
		ft_free(path);
		internal_error_msg(type);
		exit (EXIT_FAILURE);
	}
	ft_free_split(split);
	ft_free(path);
}
