/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 00:15:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:33 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		write_number_in_file(int nb, int fd)
{
	write(fd, &nb, sizeof(int));
}

static void	write_header(int fd, int width, int heigth)
{
	write(fd, "BM", 2);
	write_number_in_file(54 + 4 * width * heigth, fd);
	write_number_in_file(0, fd);
	write_number_in_file(54, fd);
	write_number_in_file(40, fd);
	write_number_in_file(width, fd);
	write_number_in_file(heigth, fd);
	write_number_in_file(2097153, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
}

void		create_bmp(char *clr, int width, int heigth)
{
	int		fd;
	char	c;
	int		y;
	int		x;

	fd = open("./image.bmp", O_CREAT | O_WRONLY, 777);
	write_header(fd, width, heigth);
	y = heigth - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < width)
		{
			c = clr[(y * width + x) * 4];
			write(fd, &c, 1);
			c = clr[(y * width + x) * 4 + 1];
			write(fd, &c, 1);
			c = clr[(y * width + x) * 4 + 2];
			write(fd, &c, 1);
			c = (char)255;
			write(fd, &c, 1);
			x++;
		}
		y--;
	}
}
