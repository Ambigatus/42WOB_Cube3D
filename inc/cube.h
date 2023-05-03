/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:20:04 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/03 18:43:10 by ddzuba           ###   ########.fr       */
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

/******************************************************************************/
/*								ERRORS DEFINE								  */
/******************************************************************************/

# define ARG 			"This program requires only one argument"
# define FORMAT 		"Invalid map format"
# define ACCESS 		"Failed to open map"
# define PATH_NO 		"Invalid path for north texture"
# define PATH_SO 		"Invalid path for south texture"
# define PATH_WE 		"Invalid path for west texture"
# define PATH_EA 		"Invalid path for east texture"
# define RGB_F 			"Floor color isn't in RGB format"
# define RGB_C 			"Ceiling color isn't in RGB format"
# define LOT_OF_SET 	"Too many settings"
# define MISSING		"Missing setting informations"
# define INVALID_SET 	"Invalid setting's line"
# define INVALID_MAP 	"Invalid map"
# define MALLOC 		"Malloc failed"
/******************************************************************************/
/*							    ENUM STRUCTS							  	  */
/******************************************************************************/

/******************************************************************************/
/*							TEXTURE DEFINE				 				  	  */
/******************************************************************************/

# define TEXT_NO	"42WOB_Cube3D/textures/bluestone.png"
# define TEXT_SO	"42WOB_Cube3D/textures/bluestone.png"
# define TEXT_EA	"42WOB_Cube3D/textures/bluestone.png"
# define TEXT_WE	"42WOB_Cube3D/textures/bluestone.png"

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
/*							DELIMITERS DEFINE					 			  */
/******************************************************************************/

# define WHITE "\t\v\r\f "
/******************************************************************************/
/*							   LIST OF FUNCTIONS, PARSER					  */
/******************************************************************************/

void			initialization(t_system *system);
int				cmp_setup(t_system *system, char *line, char *type, int val);
char			**split_and_validate_line(t_system *system, char *line);
void			color_parsing(t_system *system, char *line, int type);
void			texture_parsing(t_system *system, char *line, int type);
void			parsing(int argc, char **argv, t_system *system);
void			init_image(t_system *system);
void			free_initialization(t_system *system, char *line);
int				valid_char(char c);
void			only_valid_char(t_system *system);
int				check_walls(t_system *system, float x, float y);
void			textures_init(t_system *system);
void			system_init(t_system *system);

/******************************************************************************/
/*							   LIST OF FUNCTIONS, MAP						  */
/******************************************************************************/

char			*open_map(t_system *system, char *line);
void			player_check(t_system *system, char elmt, int y, int x);
void			validate_space_around(t_system *system);
char			*map_validation(t_system *system, char *line);
void			end_map_parsing(t_system *system, char *msg, char *line);
void			get_fd(t_system *system, char *file);
int				check_info(int *info);
int				check_lines(char *line, int type);
void			find_the_height(t_system *system);
void			space_validation(t_system *system);
void			walls_validation(t_system *system);

/******************************************************************************/
/*						 LIST OF FUNCTIONS, GRAPHIC ENGINE					  */
/******************************************************************************/

void			ft_3d_engine(t_system *system, float *draw, float end, \
							t_ray *ray);
void			ft_mlx_put_pixel(t_cube *cube, int x, int y, int color);
unsigned int	ft_mlx_get_pixel(t_image *img, int x, int y);
float			update_angle(float angle);
void			update_data_ray(float *ray, float *o, int *dof);
float			calc_dist(float ax, float ay, float bx, float by);

/******************************************************************************/
/*						 LIST OF FUNCTIONS, RAY CASTING						  */
/******************************************************************************/

float			*init_ray_data(t_system	*data, float *elem);
float			*get_data_ray(t_system *data, t_ray *ray, int type);
float			check_distance(t_ray *ray);
void			draw_seeing_rays(t_system *data);
int				check_wall(t_system *data, float x, float y);
void			draw_column(t_system *data, int i, t_ray *ray);
void			update_y_color(float *draw, t_system *data, float end, \
								t_ray *ray);
float			update_wall_end(float end, t_ray *ray);
int				*depth_of_field_ver(t_system *data, float *ray, \
									float *ray_orig, float ra);
int				*depth_of_field_hor(t_system *data, float *ray, \
									float *ray_orig, float ra);
void			get_ray_val(t_system *system, t_ray *ray, int *dof, int type);

/******************************************************************************/
/*						 LIST OF FUNCTIONS, KEYS							  */
/******************************************************************************/
int				move_player(int keycode, t_system *data);
int				ft_exit(int keycode);
int				keyrelease(int keycode, t_system *data);
int				keypress(int keycode, t_system *data);

/******************************************************************************/
/*						 LIST OF FUNCTIONS, ERRORS							  */
/******************************************************************************/
int				error_msg(char *msg);

#endif