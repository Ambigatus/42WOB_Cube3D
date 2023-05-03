/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_part_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:13:35 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/03 19:02:49 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	textures_init(t_system *system)
{
	int	face;

	face = NO;
	while (face < 4)
	{
		system->cube->tex[face] = malloc(sizeof(t_image));
		system->cube->tex[face]->img = mlx_xpm_file_to_image(&system->cube->mlx,
				system->texture[face], &system->cube->tex[face]->w_text,
				&system->cube->tex[face]->h_text);
		if (!system->cube->tex[face]->img)
			exit(error_msg(MALLOC));
		system->cube->tex[face]->address
			= mlx_get_data_addr(system->cube->tex[face]->img,
				&system->cube->tex[face]->bits_per_pixel,
				&system->cube->tex[face]->line_length,
				&system->cube->tex[face]->endian);
		face++;
	}
}

void	system_init(t_system *system)
{
	system->cube = malloc(sizeof(t_system));
	if (!system->cube)
		end_map_parsing(system, MALLOC, NULL);
	system->cube->player.px = system->player[2] * system->map_s + 28;
	system->cube->player.py = system->player[1] * system->map_s + 28;
	system->cube->player.pa = system->player[0];
	system->cube->player.pdx = cos(system->cube->player.pa) * 5;
	system->cube->player.pdy = sin(system->cube->player.pa) * 5;
	system->cube->mlx = mlx_init();
	mlx_do_key_autorepeaton(system->cube->mlx);
	system->cube->window = mlx_new_window(system->cube->mlx,
			WIN_W, WIN_H, "Cube3D");
	init_image(system);
	textures_init(system);
}
