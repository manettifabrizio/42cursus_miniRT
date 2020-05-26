/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:21:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/26 00:38:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

typedef	struct	s_sphere
{
	t_point				c;
	float				d;
	t_color				rgb;
}				t_sphere;

typedef struct	s_plane
{
	t_point				a;
	t_point				v;
	t_color				rgb;
}				t_plane;

typedef	struct	s_shapes
{
	t_sphere			sp;
	t_plane				pl;
	struct s_shapes		*next;
}				t_shapes;