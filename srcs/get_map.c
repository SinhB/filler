/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:18:46 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/09 17:50:09 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_map_size(t_filler *filler)
{
	char	*line;
	int		i;
	int		error;

	i = 0;
	error = 1;
	line = (void *)0;
	get_next_line(0, &line);
	if (ft_strncmp(line, "Plateau ", 8))
		error = 0;
	if (!(filler->map.x = ft_atoi(&line[8])))
		error = 0;
	i = ft_cntdigit(filler->map.x) + 1;
	if (!(filler->map.y = ft_atoi(&line[8 + i])))
		error = 0;
	i += ft_cntdigit(filler->map.y);
	if (line[8 + i] != ':')
		error = 0;
	ft_memdel((void**)&line);
	return (error);
}
