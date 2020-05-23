/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:50:10 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		i;
	int		z;
	char	*s3;

	x = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	z = ft_strlen(s1);
	if (!(s3 = (char*)malloc((z + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		s3[x + i] = s2[x];
		x++;
	}
	s3[x + i] = '\0';
	return (s3);
}
