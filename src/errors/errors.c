/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:02:40 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/26 17:16:53 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	error_msg(char *msg)
{
	printf("Hey, u got an ERROR!\n%s ", msg);
	return (1);
}
