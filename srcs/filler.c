/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:50 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/08 19:32:06 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int	get_player_number(t_filler *filler)
{
	char *line;

	line = (void *)0;
	ft_printf("saluttoi\n");
	get_next_line(0, &line);
	ft_printf("line :%s\n", line);
	ft_printf("line[10] :%c\n", line[10]);
	if (line[10] == '1')
		filler->p_nb = 1;
	else
		filler->p_nb = 2;
	ft_printf("p_nb = %d\n", filler->p_nb);
	return (1);
}

int main(void)
{
	t_filler filler;

	ft_bzero(&filler, sizeof(filler));
	if (!(get_player_number(&filler)))
		return (0);
	ft_printf("salut\n");
return (0);
}
