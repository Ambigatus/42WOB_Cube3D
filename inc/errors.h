/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:30:36 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/01 17:16:59 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

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
/*								FUNCTIONS LIST								  */
/******************************************************************************/

int	error_msg(char *msg);

#endif