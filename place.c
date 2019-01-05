/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 21:04:26 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/05 13:27:20 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

int		place(char **mappie, t_mino *mino, int i, int j)
{
	while (mino->crd)
	{
		if (mino->crd[i][j] == '.')
		{
			i++;
		}
		else
			mappie[i][j] = mino->crd[i][j];
	}
}
//take in map
//try to place pieces on map
//use recurssion somewhere
//if pieces don't fit, make new map

