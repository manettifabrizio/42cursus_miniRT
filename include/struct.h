/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:05:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/20 21:11:49 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_point
{
	float	x;
	float	y;
	float	z;
}					t_point;

typedef struct		s_ray
{
	t_point		*orig;
	int			t;
	t_point		*dir; 
}					t_ray;

typedef struct 		s_setting
{
	unsigned int	width;
	unsigned int	heigth;
	float			alpha; //angolo del campo visivo
	float			scale;
	float			imageAR;
}					t_setting;
