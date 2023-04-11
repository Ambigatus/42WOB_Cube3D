/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:31 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/11 18:19:27 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	main(int argc, char **argv)
{
	t_system	*system;

	system = malloc(sizeof(t_system));
	if (!system)
		exit (error_msg(MALLOC));
	parsing(argc, argv, system);
	//initialization of cube
	//ray casting
	mlx_hook();
	mlx_hook();
	mlx_hook();
	mlx_loop_hook();
	mlx_loop(system->cube->mlx);
	exit(0);
}
