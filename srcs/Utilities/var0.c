/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:01:20 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/23 09:35:24 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int		check(char *line, t_uint y)
{
	t_uint	x;
	t_uint	nbr;

	x = 0;
	nbr = 0;
	// printf("line = %s\n", line);
	while (line[x])
	{
		if (ft_isdigit(line[x]) && (line[x + 1] == ' ' || (line[x + 1] >= 8 && \
			line[x + 1] <= 13) || line[x + 1] == '\0'))
			nbr++;
		x++;
	}
	// printf("nbr = %d\n", nbr);
	if (nbr != y)
		return (1);
	return (0);
}