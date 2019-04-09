/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:19:27 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/09 17:47:39 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_player_number(t_filler *filler)
{
	char	*line;
	int		i;
	int		error;

	i = 0;
	error = 1;
	line = (void *)0;
	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$ exec p", 10))
		error = 0;
	if (line[12] != ':')
		error = 0;
	if (line[14] == '[')
		while(line[14 + i])
			i++;
	else
		error = 0;
	if (line[13 + i] != ']')
		error = 0;
	if (line[10] == '1')
		filler->p_nb = 1;
	else if (line[10] == '2')
		filler->p_nb = 2;
	else
		error = 0;
	ft_memdel((void**)&line);
	return (error);
}
