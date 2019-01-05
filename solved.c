/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:17:28 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/04 14:20:34 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

int		solved(t_mino *minos)
{
	int		solver;
	int		size;
	char	**mappie;

	size = 2;
	solver = 0;
	while (solver == 0)
	{
		mappie = map(size);
		solver = place(mappie, minos);
		//free(mappie);
		size++;
	}
}
