/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:27:54 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/05 12:04:49 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

t_mino			*cuty(t_mino *valid)
{
	int 	len;
	int		x;
	int		y;

	len = 4;
	x = 0;
	y = 0;
	while (valid->coordinates[0][x] != '\0')
	{
		while (valid->coordinates[y][x] == '.' && valid->coordinates[y + 1][x] == '.' &&
		valid->coordinates[y + 2][x] == '.' && valid->coordinates[y + 3][x] == '.' && x < len)
		{
			ft_memmove(valid->coordinates[y] + x, valid->coordinates[y] + x + 1, len);
			ft_memmove(valid->coordinates[y + 1] + x, valid->coordinates[y + 1] + x + 1, len);
			ft_memmove(valid->coordinates[y + 2] + x, valid->coordinates[y + 2] + x + 1, len);
			ft_memmove(valid->coordinates[y + 3] + x, valid->coordinates[y + 3] + x + 1, len);
			print2d(valid->coordinates);
			puts("");
			len--;
		}
		x++;
	}
	return (valid);
}
/*
int			cutx(t_mino *valid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (valid->coordinates[y][0] == '.' && valid->coordinates[y][1] == '.' &&
	valid->coordinates[y][2] == '.' && valid->coordinates[y][3] == '.')
	{
		while (x < 4)
		{
			ft_memmove(valid->coordinates[x][y], valid->coordinates[x][y] + 1, 5)
			y++;
		}
		x++;
	}
}

t_mino		*cuter(t_mino *valid)
{

}
*/
