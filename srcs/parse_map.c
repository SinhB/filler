/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/10 18:58:57 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->map.height)
	{
		ft_printf("%s\n",filler->map.board[i]);
		i++;
	}
}

int	parse_map(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (filler->init == 0)
		get_next_line(0, &line);
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
