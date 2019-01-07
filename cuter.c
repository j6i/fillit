/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:27:54 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/06 19:25:30 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

t_mino		*cuty(t_mino *valid)
{
	int		len;
	int		x;

	len = 4;
	x = 0;
	while (valid->crd[0][x] != '\0')
	{
		while (valid->crd[0][x] == '.' && valid->crd[1][x] == '.' &&
		valid->crd[2][x] == '.' && valid->crd[3][x] == '.' && x < len)
		{
			ft_memmove(valid->crd[0] + x, valid->crd[0] + x + 1, len);
			ft_memmove(valid->crd[1] + x, valid->crd[1] + x + 1, len);
			ft_memmove(valid->crd[2] + x, valid->crd[2] + x + 1, len);
			ft_memmove(valid->crd[3] + x, valid->crd[3] + x + 1, len);
			len--;
		}
		x++;
	}
	return (valid);
}

t_mino		*cutx(t_mino *valid)
{
	int		len;
	int		y;
	int		y2;
	int		x;

	y = 0;
	x = 0;
	while (valid->crd[y] != 0)
	{
		y2 = y;
		len = ft_strlen(valid->crd[y]);
		while (valid->crd[y][x] != '\0' && valid->crd[y][x] == '.')
			x++;
		y++;
		while (x == len && valid->crd[y2 + 1] != 0)
		{
			ft_strcpy(valid->crd[y2], valid->crd[y2 + 1]);
			y2++;
			y = 0;
		}
		if (x == len && valid->crd[y2 + 1] == 0)
			ft_strdel(&valid->crd[y2]);
		x = 0;
	}
	return (valid);
}

t_mino		*cut_hash(t_mino *valid, int id)
{
	int		y;
	int		x;

	y = 0;
	valid->id = id;
	while (valid->crd[y] != 0)
	{
		x = 0;
		while (valid->crd[y][x] != 0)
		{
			if (valid->crd[y][x] == '#')
				valid->crd[y][x] = valid->id + 'A';
			x++;
		}
		y++;
	}
	return (valid);
}

t_mino		*cuter(t_mino *valid, int id)
{
	valid = cuty(valid);
	valid = cutx(valid);
	valid = cut_hash(valid, id);
	return (valid);
}
