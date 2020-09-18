/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:40:52 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/16 15:57:14 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_color		compute_clr(t_shapes o, t_light l, double fratio, double shad)
{
	t_color clr;
	
	clr = mix_clr(l.clr, o.objclr, l.rat * fratio * shad);
	print_clr(clr, "clr");
	return (clr);
}