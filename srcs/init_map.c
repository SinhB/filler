/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:49:01 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/10 18:00:25 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_map(t_filler *filler)
{
	int i;
	int j;

	filler->size = filler->map.width * filler->map.height;
	filler->map.board = (char**)palloc(sizeof(char*) * filler->map.height);
	i = 0;
	while (i < filler->map.height)
	{
		j = 0;
		while (j < filler->map.width)
		{
			filler->map.board[i] = (char*)palloc(sizeof(char) * filler->map.width + 1);
			//filler->map.board[i][filler->map.width] = '\0';
			ft_bzero(filler->map.board[i], filler->map.width);
			j++;
		}
		i++;
	}
	filler->init = 1;
	return (1);
}
