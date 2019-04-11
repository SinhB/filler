/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/11 03:08:08 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->map.height)
	{
		ft_dprintf(2, "%s\n", filler->map.board[i]); //fd = 2 to print without affecting VM input -> only for testing
		i++;
	}
}

int	parse_map(t_filler *filler)
{
	char	*line;
	int		i;
	int		error;

	i = 0;
	error = 1;
	if (filler->init == 0)
	{
		get_next_line(0, &line);
		if (!check_features(filler, line, 1))
		{
			//ft_memdel((void**)&line);
			return (errors(1));
		}
	}
	get_next_line(0, &line);
	while (i < filler->map.height)
	{
		get_next_line(0, &line);
		while (ft_isdigit(*line) || ft_isblank(*line))
			line++;
		ft_strcpy(filler->map.board[i], &*line);
		//ft_memdel((void**)&line);
		i++;
	}
	filler->init = 0;
	print_map(filler);
	return (1);
}
