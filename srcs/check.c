/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 16:01:14 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_features(t_filler *filler, char *line, int i)
{
	int error;
	int n;

	n = 0;
	if (i == 1)
		error = ft_strcmp(filler->m_features, line) ? 0 : 1;
	else
		error = ft_strcmp(filler->p_features, line) ? 0 : 1;
	return (error);
}

int	check_p_line(t_filler *filler, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '*')
			return (0);
		if (line[i] == '*')
			filler->piece.cnt++;
	}
	if (i != filler->piece.width)
		return (0);
	return (1);
}
