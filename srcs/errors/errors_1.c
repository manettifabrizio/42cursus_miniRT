/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:20:08 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/19 20:12:36 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	parse_errors(t_uint line, int x)
{
	if (x == -1)
	{
		ft_putstr("\033[0;31mSyntax Error\033[0m in .rt file at line : "); 
		ft_putnbr((int)line + 1);
		ft_putchar('\n');
		exit(1);
	}
	else if (x == 0)
	{
		ft_putstr("\033[0;31mSyntax Error\033[0m in .rt file : camera parameters not set\n"); 
	}

}

void	parse_errno(int errnum)
{
	if (errnum == 0)
		ft_putstr_fd("\033[0;31mError\033[0m : File is empty\n", 2);
	else
	{
		strerror(errnum);
		perror("\033[0;31mError\033[0m ");
	}
	exit(1);
}

void	mlx_error(t_mlx d)
{
	ft_memdel(&d.img);
	//ft_strdel(&c.str);
	ft_memdel((void*)&d);
	exit(EXIT_FAILURE);
}