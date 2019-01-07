/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printn2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:40:54 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/06 18:45:00 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	printn2d(char **s, size_t num)
{
	size_t		i;

	i = 0;
	while (i < num)
	{
		write(1, s[i], num);
		write(1, "\n", 1);
		i++;
	}
}
