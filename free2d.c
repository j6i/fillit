/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:30:16 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/05 12:34:46 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	free2d(char **twod)
{
	while (**twod != NULL)
	{
		ft_strdel(&twod);
		**twod++;
	}
	free(twod);
}