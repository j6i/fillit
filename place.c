/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 21:04:26 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/06 19:26:11 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

int		map_check(t_map *mappie, t_mino *mino)
{
	int		x2;
	int		y;
	int		x;

	y = 0;
	x = ft_strlen(mino->crd[y]);
	x2 = ft_strlen(mappie->map[y]);
	if (x > x2)
		return (0);
	while (mappie->map[y] != '\0')
		y++;
	if (mappie->map[y] == '\0' && mino->crd[y] != '\0')
		return (0);
	return (1);
}

int		piece_checker(t_map *mappie, t_mino *mino, int x, int y)
{
	int		mx;
	int		my;

	my = 0;
	mx = 0;
	while (mino->crd[my])
	{
		mx = 0;
		while (mino->crd[my][mx] != 0)
		{
			if (mappie->map[y + my][x + mx] != '.' && mino->crd[my][mx] != '.')
				return (0);
			if (x + mx >= mappie->size || y + my >= mappie->size)
				return (0);
			mx++;
		}
		my++;
	}
	return (1);
}

int		placer(t_map *mappie, t_mino *mino, int x, int y)
{
	int		mx;
	int		my;

	my = 0;
	mx = 0;
	if (!piece_checker(mappie, mino, x, y))
	{
		return (0);
	}
	while (mino->crd[my])
	{
		mx = 0;
		while ((y + my) < mappie->size && (x + mx) < mappie->size &&
		mino->crd[my][mx])
		{
			if (mappie->map[y + my][x + mx] == '.' && mino->crd[my][mx] != '.')
				mappie->map[y + my][x + mx] = mino->crd[my][mx];
			mx++;
		}
		my++;
	}
	return (1);
}

int		piece_reset(t_map *mappie, t_mino *mino, int x, int y)
{
	int		mx;
	int		my;

	my = 0;
	mx = 0;
	while (mino->crd[my])
	{
		mx = 0;
		while ((y + my) < mappie->size && (x + mx) < mappie->size &&
		mino->crd[my][mx])
		{
			if (mappie->map[y + my][x + mx] != '.' && mino->crd[my][mx] != '.')
				mappie->map[y + my][x + mx] = '.';
			mx++;
		}
		my++;
	}
	return (1);
}
