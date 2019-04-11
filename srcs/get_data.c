/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:33:27 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/11 02:54:45 by yabecret         ###   ########.fr       */
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
	filler->m_features = ft_strdup(line);
	if (ft_strncmp(line, "Plateau ", 8))
		error = 0;
	if (!(filler->map.height = ft_atoi(&line[8])))
		error = 0;
	i = ft_cntdigit(filler->map.height) + 1;
	if (!(filler->map.width = ft_atoi(&line[8 + i])))
		error = 0;
	i += ft_cntdigit(filler->map.width);
	if (line[8 + i] != ':')
		error = 0;
	ft_memdel((void**)&line);
	return (error);
}

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
