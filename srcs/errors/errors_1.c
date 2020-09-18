/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:20:08 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/18 19:43:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	start_errors(int ac, char **av, t_objects *obj)
{
	int x;

	if (ac > 1)
	{
		x = ft_strlen(av[1]);
		if (!(av[1][x - 1] == 't' && av[1][x - 2] == 'r' 
				&& av[1][x - 3] == '.'))
		{
			ft_putstr("\033[0;31mError:\033[0m Invalid file format.\n");
			exit(1);
		}
	}
	else
	{
		ft_putstr("\033[0;31mError:\033[0m Missing .rt file.\n");
		exit(1);
	}
}

void	mlx_error(t_mlx d)
{
	ft_memdel(&d.img);
	//ft_strdel(&c.str);
	ft_memdel((void*)&d);
	exit(EXIT_FAILURE);
}

void	parse_errors(t_uint x)
{
	if (x == 0)
	{
		ft_putstr("\033[0;31mError:\033[0m Allocation failed\n");
		exit(0);
	}
	else if (x == 1)
	{
		ft_putstr("\033[0;31mError:\033[0m fd reading failed\n");
		exit(0);
	}
	else if (x == 2)
	{
		ft_putstr("\033[0;31mSyntax Error\033[0m in .rt file : \
			missing camera.\n");
		exit(0);
	}

}

void	parse_errno(int errnum)
{
	if (errnum == 0)
		ft_putstr_fd("\033[0;31mError\033[0m : File is empty.\n", 2);
	else
	{
		strerror(errnum);
		perror("\033[0;31mError\033[0m");
	}
	exit(1);
}

void	rt_errors(t_uint x, char *obj, t_uint nline)
{
	if (x == 0)
	{
		ft_putstr("\033[0;31mMissing Parameter\033[0m in ");
		ft_putstr(obj);
		ft_putstr(" declaration at line: ");
		ft_putnbr(nline + 1);
		ft_putstr(".\n");
		exit(0);
	}
	else if (x == 1)
	{
		ft_putstr("\033[0;31mInvalid Value\033[0m for the ");
		ft_putstr(obj);
		ft_putstr(" at line: ");
		ft_putnbr(nline + 1);
		ft_putstr(".\n");
		exit(0);
	}
}