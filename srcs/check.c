/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 18:30:10 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
		i++;
	}
	if (i != filler->piece.width)
		return (0);
	return (1);
}

int	check_p_pos(t_filler *filler, int y, int x)
{
	int i;

	i = 0;
	while (i < filler->piece.cnt)
	{
		while (j < filler->piece.cnt)
		{
			
		}
		i++;
	}
}
