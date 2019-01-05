/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 19:03:31 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/04 19:49:02 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

int		hash_per(char **coord)
{
	int		i;
	int		j;

	i = 0;
	while (coord[i])
	{
		j = 0;
		while (coord[i][j])
		{
			if (coord[i][j] != '#' && coord[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		hash_num(char **coord)
{
	int		i;
	int		j;
	int		hash;
	int		per;

	i = 0;
	hash = 0;
	per = 0;
	while (coord[i])
	{
		j = 0;
		while (coord[i][j])
		{
			if (coord[i][j] == '#')
				hash++;
			if (coord[i][j] == '.')
				per++;
			j++;
		}
		i++;
	}
	return (hash == 4 && per == 12);
}

int		six_eight(char **coord)
{
	int		i;
	int		j;
	int		cnct;

	i = -1;
	cnct = 0;
	while (coord[++i] != '\0')
	{
		j = -1;
		while (coord[i][++j] != '\0')
		{
			if (coord[i][j] == '#')
			{
				if ((j + 1) <= 3 && coord[i][j + 1] == '#')
					cnct++;
				if ((j - 1) >= 0 && coord[i][j - 1] == '#')
					cnct++;
				if ((i + 1) <= 3 && coord[i + 1][j] == '#')
					cnct++;
				if ((i - 1) >= 0 && coord[i - 1][j] == '#')
					cnct++;
			}
		}
	}
	return (cnct == 8 || cnct == 6);
}

int		val_mino(t_mino *head)
{
	t_mino	*vald;

	vald = head;
	while (vald != NULL)
	{
		if (hash_per(vald->coordinates) == 0)
			return (-1);
		if (hash_num(vald->coordinates) == 0)
			return (-1);
		if (six_eight(vald->coordinates) == 0)
			return (-1);
		vald = cuty(vald);
		puts("exited cuty");
		vald = vald->next;
	}
	return (0);
}
