/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:17:28 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/06 19:12:25 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"
#include <stdlib.h>

int		recurse(t_mino *mino, t_map *mappie, int size)
{
	int x;
	int y;

	if (mino == NULL)
		return (1);
	y = 0;
	while (y < mappie->size)
	{
		x = 0;
		while (x < mappie->size)
		{
			if (placer(mappie, mino, x, y))
			{
				if (recurse(mino->next, mappie, mappie->size))
					return (1);
				else
					piece_reset(mappie, mino, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		solved(t_mino *minos)
{
	t_map	*mappie;

	mappie = map_new(2);
	while (!recurse(minos, mappie, mappie->size))
		mappie->size++;
	printn2d(mappie->map, mappie->size);
	return (1);
}
