/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:17:28 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/06 16:59:43 by jgabelho         ###   ########.fr       */
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
			if (placer(mappie, mino, x, y, mappie->size))
			{
				if (recurse(mino->next, mappie, mappie->size))
					return (1);
				else
					piece_reset(mappie, mino, x, y, mappie->size);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		solved(t_mino *minos)
{
	int		size;
	t_map	*mappie;

	size = 2;
	mappie = map_new(size);
	while (!recurse(minos, mappie, mappie->size))
	{
		mappie->size++;
	}
	print2d(mappie->map);
	return (1);
}
