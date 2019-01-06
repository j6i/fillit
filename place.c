/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 21:04:26 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/05 18:23:00 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

int		place_check(char **mappie, t_mino *mino, int x, int y)
{
	int		x2;
	int		y2;
	int		tmpx;

	x2 = 0;
	y2 = 0;
	tmpx = x;
	while (mino->crd[y2][x2] != 0 && mappie[y][x] != '\0')
	{
		if (mappie[y][x] == '\0' && mino->crd[y2][x2] != '\0')
			return (0);
		if (mino->crd[y2][x2] == '\0')
		{
			y++;
			y2++;
			x2 = -1;
			x = tmpx - 1;
		}
		x++;
		x2++;
	}
	return (1);
}

int		place(char **mappie, t_mino *mino, int x, int y)
{
	int		x2;
	int		y2;
	int		tmpx;

	x2 = 0;
	y2 = 0;
	tmpx = x;
	if ((place_check(mappie, mino, x, y)))
	{
		while (mino->crd[y2][x2] != 0 && mappie[y][x] != '\0')
		{
			if (mino->crd[y2][x2] == '\0')
			{
				y++;
				y2++;
				x2 = 0;
				x = tmpx;
			}
			mappie[y][x] = mino->crd[y2][x2];
			x++;
			x2++;
		}
		puts("PLACED");
		print2d(mappie);
		puts("");
		return (1);
	}
	else
		return (0);
}
//take in map
//try to place pieces on map
//use recurssion somewhere
//if pieces don't fit, make new map

