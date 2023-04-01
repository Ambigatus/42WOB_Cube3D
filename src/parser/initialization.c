/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:56:01 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/01 18:07:40 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static void	info_init(t_system *system)
{
	int	i;

	i = 0;
	system->info = malloc(sizeof(int) * 6);
	if (!system->info)
	{
		close(system->fd);
		ft_free(system);
		exit (error_msg(MALLOC));
	}
	while (i < 6)
	{
		system->info[i] = 0;
		i++;
	}
}

static void	colors_init(t_system *system)
{
	int	i;

	i = 0;
	system->color = malloc(sizeof(int) * 2);
	if (!system->color)
	{
		ft_free(system->info);
		close(system->fd);
		ft_free(system);
		exit (error_msg(MALLOC));
	}
	while (i < 2)
	{
		system->color[i] = 0;
		i++;
	}
}

static void	player_init(t_system *system)
{
	int	i;

	i = 0;
	system->player = malloc(sizeof(double) * 3);
	if (!system->player)
	{
		ft_free(system->info);
		ft_free(system->color);
		close(system->fd);
		ft_free(system);
		exit (error_msg(MALLOC));
	}
	while (i < 3)
	{
		system->player[i] = -1;
		i++;
	}
}

static void	texture_init(t_system *system)
{
	int	i;

	i = 0;
	system->texture = malloc(sizeof(char *) * 4);
	if (!system->texture)
	{
		ft_free(system->info);
		ft_free(system->color);
		close(system->fd);
		ft_free(system);
		exit (error_msg(MALLOC));
	}
	while (i < 4)
	{
		system->texture[i] = ft_strdup("\0");
		if (!system->texture[i])
		{
			free_initialization(system, NULL);
			exit (error_msg(MALLOC));
		}
		i++;
	}
	system->texture[i] = 0;
}

/* Initialization of game data */
void	initialization(t_system *system)
{
	info_init(system);
	colors_init(system);
	player_init(system);
	texture_init(system);
}
