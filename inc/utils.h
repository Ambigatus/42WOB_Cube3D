/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:20:07 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/07 18:31:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cube.h"

/******************************************************************************/
/*								TEXTURE DEFINE								  */
/******************************************************************************/

/******************************************************************************/
/*								MATH DEFINE								 	  */
/******************************************************************************/

# define PI				3.141592653589793238
# define P2  			1.57079632679
# define P3  			4.71238898038

# define SOUTH  		1.57079632679
# define NORTH  		4.71238898038
# define WEST			3.141592653589793238
# define EAST			6.28318530718

/******************************************************************************/
/*						MOVE AND ROTATION SPEED DEFINE				 	 	  */
/******************************************************************************/

# define MOVE_SPEED		0.3
# define ROT_SPEED		0.04

/******************************************************************************/
/*							WINDOW AND FOV DEFINE				 		 	  */
/******************************************************************************/

# define WIN_W			1024
# define WIN_H 			512
# define FOV 			1.57079632679

/******************************************************************************/
/*							KEYBOARD DEFINE				 				  	  */
/******************************************************************************/

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT 		123
# define KEY_RIGHT 		124
# define ESC 			53

/******************************************************************************/
/*							MOVING STRUCT				 			  		  */
/******************************************************************************/

/* Keyboard handler */
typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
}	t_key;

/******************************************************************************/
/*							DELIMITERS DEFINE					 			  */
/******************************************************************************/

# define WHITE "\t\v\r\f "

/******************************************************************************/
/*							FUNCTIONS LIST, PARSER				 			  */
/******************************************************************************/

void			free_initialization(t_system *system, char *line);
int				valid_char(char c);
void			only_valid_char(t_system *system);
int				check_walls(t_system *system, float x, float y);

/******************************************************************************/
/*							FUNCTIONS LIST, MAP					 			  */
/******************************************************************************/

void			end_map_parsing(t_system *system, char *msg, char *line);
void			get_fd(t_system *system, char *file);
int				check_info(int *info);
int				check_lines(char *line, int type);
void			find_the_height(t_system *system);
void			space_validation(t_system *system);
void			walls_validation(t_system *system);

/******************************************************************************/
/*						FUNCTIONS LIST, GRAPHIC	ENGINE					 	  */
/******************************************************************************/

void			ft_mlx_put_pixel(t_cube *cube, int x, int y, int color);
unsigned int	ft_mlx_get_pixel(t_image *img, int x, int y);
float			update_angle(float angle);
void			update_data_ray(float *ray, float *o, int *dof);

#endif