/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:31:47 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/22 18:49:58 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int 	main(void)
{
	char	*line;
	t_skrr	skrr;
//	int 	fd;

	skrr.sh = -1;
//	fd = open("test.txt", O_WRONLY);
//	fd = open("middle_map.txt", O_RDONLY);
	while (get_next_line(0, &line) > 0)
	{
//		dprintf(fd, "%s\n", line);
		basic_info(&line, &skrr);
		if (line[0] == '0')
			g_map[++skrr.x_map] = ft_strsub(line, 4, ((size_t)skrr.map_size_y + 4));
		if (line[0] == '.' || line[0] == '*')
			g_piece[++skrr.x_piece] = ft_strsub(line, 0, ((size_t)skrr.piece_size_y));
		if (skrr.sh == skrr.x_piece + 1)
			found_first(&skrr);
	}
//	print_info(&skrr);
	return (0);
}

void	basic_info(char **line, t_skrr *skrr)
{
	(!(ft_strncmp(*line, "$$$ exec p1", 11))) ? (skrr->player = 1) : 0;
	(!(ft_strncmp(*line, "$$$ exec p2", 11))) ? (skrr->player = 2) : 0;
	if (!(ft_strncmp(*line, "Plateau 15", 10)))
		map_set(skrr, 15, 17);
	else if (!(ft_strncmp(*line, "Plateau 24", 10)))
		map_set(skrr, 24, 40);
	else if (!(ft_strncmp(*line, "Plateau 10", 10)))
		map_set(skrr, 100, 99);
	(!(ft_strncmp(*line, "Piece", 5))) ? piece_size(line, skrr) : 0;
}

void	map_set(t_skrr *skrr, int x, int y)
{
	skrr->x_map = -1;
	skrr->x_piece = -1;
	skrr->map_size_x = x;
	skrr->map_size_y = y;
	g_map = ((char **)malloc((sizeof(char *) * skrr->map_size_x)));
}

//void	print_info(t_skrr *skrr)
//{
//	ft_printf("Player: %d\n", skrr->player);
//	ft_printf("Map size x:[%d] y:[%d]\n", skrr->map_size_x, skrr->map_size_y);
//	skrr->x_map = -1;
//	while (++skrr->x_map < skrr->map_size_x)
//		ft_printf("%s\n", g_map[skrr->x_map]);
//	ft_printf("Piece x:[%d] y:[%d]\n", skrr->piece_size_x, skrr->piece_size_y);
//	skrr->y_map = -1;
//	while (++skrr->y_map < skrr->piece_size_x)
//		ft_printf("%s\n", g_piece[skrr->y_map]);
//}
