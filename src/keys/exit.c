/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:32:53 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/15 14:35:07 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

//function for exit from a program
int	ft_exit(int keycode)
{
	if (keycode)
		exit(EXIT_SUCCESS);
	return (0);
}