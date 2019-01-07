/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 10:41:39 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/06 19:22:35 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "fillit.h"

char	**map_maker(char **mapper, int size)
{
	int		i;

	i = -1;
	mapper = malloc(sizeof(char*) * (size + 1));
	mapper[size] = NULL;
	while (++i < size)
	{
		mapper[i] = ft_strnew(size);
		mapper[i] = ft_memset(mapper[i], '.', size);
	}
	return (mapper);
}

char	**map(int size)
{
	char	**mapper;

	mapper = map_maker(mapper, size);
	return (mapper);
}
