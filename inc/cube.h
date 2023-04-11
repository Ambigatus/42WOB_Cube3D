/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:20:04 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/11 19:46:55 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/******************************************************************************/
/*								STANDART LIBS								  */
/******************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "utils.h"
# include "errors.h"

/******************************************************************************/
/*							    ENUM STRUCTS							  	  */
/******************************************************************************/

enum e_position
{
	X,
	Y,
	DIST,
	COLOR,
	POS_MAX
};

enum e_type
{
	HORIZONTAL,
	VERTICAL,
	RENDER_TEXT
};

enum e_color
{
	FLOOR,
	CEILING
};

enum e_texture
{
	NO,
	SO,
	WE,
	EA
};

/******************************************************************************/
/*							       STRUCTS							  	 	  */
/******************************************************************************/

/* Player positioning struct. 
** px - is position on x.
** py - is position on y.
** pdx - is player direction of view on x.
** pdy - the same, but on view on y.
** pa - is player angle, need for player FOV(Field Of View)*/
typedef struct s_player
{
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	float		pa;
}		t_player;

/* Image struct. Needs for manipulate image data, as read, write etc. */
typedef struct s_image
{
	void		*img;
	char		*address;
	int			bits_per_pixel;
	int			endian;
	int			w_text;
	int			h_text;
	int			line_length;
}		t_image;

/*** r: A pointer to an array of floats representing the position of the ray.
** hor: A pointer to an array of floats representing the point where the ray 
** intersects a horizontal grid line.
** ver: A pointer to an array of floats representing the point where the ray
** intersects a vertical grid line.
** dist: The distance between the player and the wall that the ray intersects.
** line_o: The line offset of the current ray being cast.
** line_h: The line height of the wall that the ray intersects.
** color: The color of the wall that the ray intersects.
** ra: The angle of the ray with respect to the player's view.
** ca: The cosine of the angle of the ray with respect to the player's view.
** texture: An array of pointers to t_img structs representing the textures
** that can be applied to the walls. */
typedef struct s_ray
{
	float		*r;
	float		*hor;
	float		*ver;
	float		dist;
	float		line_o;
	float		line_h;
	int			color;
	float		ra;
	float		ca;
	t_image		*texture[3];
}	t_ray;

/* Engine struct for cube. Keeps all important struct inside */
typedef struct s_cube
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_image		*tex[4];
	t_player	player;
	t_ray		*ray;
}	t_cube;

/* The main part of the project. Keeps all important information about
programm. Description:

**  *info: a pointer to an integer array that contains system information.
**  fd: an integer file descriptor used for file I/O operations.
**  *color: a pointer to an integer array that contains color information.
**  **texture: a pointer to an array of strings representing texture data.
**  *player: a pointer to an array of doubles containing player position
and orientation data.
**  height: the height of the game screen.
**  width: the width of the game screen.
**  map_s: a floating-point value representing the size of the game map.
**  mini_s: the size of the minimap.
**  **map: a pointer to an array of strings representing the game map.
**  *int_map: a pointer to an integer array that represents the game map as
a grid of values.
**  *cube: a pointer to a t_cube struct containing graphics system data.
**  key: a t_key struct containing keyboard input data.
**  pos_ray[2]: an integer array representing the position of a ray in the
game. */
typedef struct s_system
{
	int			*info;
	int			fd;
	int			*color;
	char		**texture;
	double		*player;
	size_t		height;
	size_t		width;
	float		map_s;
	size_t		mini_s;
	char		**map;
	int			*int_map;
	t_cube		*cube;
	t_key		key;
	int			pos_ray[2];
}	t_system;

/******************************************************************************/
/*							   LIST OF FUNCTIONS, PARSER					  */
/******************************************************************************/

void	initialization(t_system *system);
int		cmp_setup(t_system *system, char *line, char *type, int val);
char	**split_and_validate_line(t_system *system, char *line);
void	color_parsing(t_system *system, char *line, int type);
void	texture_parsing(t_system *system, char *line, int type);
void	parsing(int argc, char **argv, t_system *system);

/******************************************************************************/
/*							   LIST OF FUNCTIONS, MAP						  */
/******************************************************************************/

char	*open_map(t_system *system, char *line);
void	player_check(t_system *system, char elmt, int y, int x);
void	validate_space_around(t_system *system);
char	*map_validation(t_system *system, char *line);

/******************************************************************************/
/*						 LIST OF FUNCTIONS, GRAPHIC ENGINE					  */
/******************************************************************************/

void	ft_3d_engine(t_system *system, float *draw, float end, t_ray *ray);

/******************************************************************************/
/*						 LIST OF FUNCTIONS, KEYS							  */
/******************************************************************************/
int		move_player(int keycode, t_struct *data);

#endif