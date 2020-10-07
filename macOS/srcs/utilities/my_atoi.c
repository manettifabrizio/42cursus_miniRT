/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 11:15:09 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/07 17:41:30 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		check_letter_or_symbol(char c, int *i, t_parse p, char *obj)
{
	if (c == ',')
		(*i)++;
	else if (ft_isspace(c) == 0 && c != '\0')
	{
		rt_errors(1, obj, p.nln);
		free_array(p.rtfile, -1);
		free_lists(p.obj);
		exit(EXIT_FAILURE);
	}
}

int				spaces_and_sign(const char *s, int *x, int *c)
{
	if (s[*x] == '\0')
		return (1);
	while (s[*x] == ' ' || (s[*x] >= 8 && s[*x] <= 13))
		(*x)++;
	if (s[*x] == '-')
		return (1);
	while (s[(*x) + (*c)] == '+' || s[(*x) + (*c)] == '-')
		(*c)++;
	if ((*c) > 1)
		return (1);
	return (0);
}

int				my_atoi(const char *s, int *i, t_parse p, char *obj)
{
	int c;
	int res;

	c = 0;
	res = 0;
	if (spaces_and_sign(s, i, &c))
		return (-1);
	while (s[(*i) + c] >= '0' && s[(*i) + c] <= '9')
	{
		res *= 10;
		res += (int)s[(*i) + c] - '0';
		(*i)++;
	}
	(*i) += c;
	check_letter_or_symbol(s[*i], i, p, obj);
	return (res);
}
