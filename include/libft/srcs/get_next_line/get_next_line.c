/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:41:53 by fmanetti          #+#    #+#             */
/*   Updated: 2020/02/06 18:04:26 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*create(char **tmp)
{
	if (!(*tmp))
	{
		if (!(*tmp = malloc(1)))
			return (NULL);
		(*tmp)[0] = '\0';
	}
	return (*tmp);
}

static	void	ft_cut(char **line, char **str)
{
	int		x;
	char	*tmp;

	x = 0;
	if (ft_strchr(*str, '\n'))
	{
		while ((*str)[x] != '\n')
			x++;
		*line = ft_substr(*str, 0, x);
		tmp = ft_substr(*str, x, ft_strlen(*str) - x);
		free(*str);
		*str = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		x = ft_strlen(*str);
		*line = ft_substr(*str, 0, x);
		tmp = ft_substr(*str, x, ft_strlen(*str) - x);
		free(*str);
		*str = ft_strdup(tmp);
		free(tmp);
	}
}

static int		fucking_space(char **line, char **tmp, int bd)
{
	char	*tmp2;

	ft_cut(line, &((*tmp)));
	if (*line == NULL)
	{
		if (!(*line = malloc(sizeof(char))))
			return (-1);
		(*line)[0] = '\0';
	}
	if (bd == 0 && (*tmp)[0] == '\0')
	{
		free((*tmp));
		(*tmp) = NULL;
		return (0);
	}
	tmp2 = ft_strdup((*tmp));
	free((*tmp));
	(*tmp) = ft_substr(tmp2, 1, ft_strlen(tmp2) - 1);
	free(tmp2);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int				bd;
	char			*buf;
	static	char	*tmp;
	char			*tmp2;

	tmp = create(&tmp);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || !tmp)
		return (-1);
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((bd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bd] = '\0';
		tmp2 = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin(tmp2, buf);
		free(tmp2);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bd < 0)
		return (-1);
	free(buf);
	return (fucking_space(line, &tmp, bd));
}
