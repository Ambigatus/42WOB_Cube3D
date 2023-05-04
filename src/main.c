/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:31 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/04 16:51:31 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

//a callback function that is used with a library such as mlx_loop_hook() to 
// continuously move the player in the game. 
static int	moving(void *arg)
{
	t_system	*system;

	system = arg;
	move_player(-1, system);
	return (0);
}

int	main(int argc, char **argv)
{
	t_system	*system;

	system = malloc(sizeof(t_system));
	if (!system)
		exit (error_msg(MALLOC));
	parsing(argc, argv, system);
	system_init(system);
	draw_seeing_rays(system);
	mlx_hook(system->cube->window, 3, 3, keyrelease, system);
	mlx_hook(system->cube->window, 2, 2, keypress, system);
	mlx_hook(system->cube->window, 17, 0L, ft_exit, system->cube);
	mlx_loop_hook(system->cube->mlx, moving, system);
	mlx_loop(system->cube->mlx);
	exit(0);
}
