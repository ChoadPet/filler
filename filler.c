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
	int 	fd;

	skrr.i = -1;
	skrr.j = -1;
	fd = open("small_map.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		basic_info(&line, &skrr);
		(skrr.i == -1) ? g_map = ((char **)malloc((sizeof(char *) * skrr.map_size_x))) : 0;
		if (line[0] == '0')
			g_map[++skrr.i] = ft_strsub(line, 4, ((size_t)skrr.map_size_y + 4));
		(skrr.j == -1) ? g_piece = ((char **)malloc(sizeof(char *) * skrr.piece_size_x)) : 0;
		if (line[0] == '.' || line[0] == '*')
			g_piece[++skrr.j] = ft_strsub(line, 0, ((size_t)skrr.map_size_y));
	}
	lets_play(&skrr);
	print_info(&skrr);
	close(fd);
	return (0);
}

void	basic_info(char **line, t_skrr *skrr)
{
	(!(ft_strncmp(*line, "$$$ exec p1", 11))) ? (skrr->player = 1) : 0;
	(!(ft_strncmp(*line, "$$$ exec p2", 11))) ? (skrr->player = 2) : 0;
	if (!(ft_strncmp(*line, "Plateau 15", 10)))
	{
		skrr->map_size_x = 15;
		skrr->map_size_y = 17;
	}
	else if (!(ft_strncmp(*line, "Plateau 24", 10)))
	{
		skrr->map_size_x = 24;
		skrr->map_size_y = 40;
	}
	else if (!(ft_strncmp(*line, "Plateau 10", 10)))
	{
		skrr->map_size_x = 100;
		skrr->map_size_y = 99;
	}
	(!(ft_strncmp(*line, "Piece", 5))) ? piece_size(line, skrr) : 0;
}

void 	piece_size(char **line, t_skrr *skrr)
{
	while (**line)
	{
		if ((**line == ' ') && (*line)++)
		{
			skrr->piece_size_x = ft_atoi(*line);
			while (**line != ' ')
				(*line)++;
			skrr->piece_size_y = ft_atoi(*line);
		}
		(*line)++;
	}
}

void	lets_play(t_skrr *skrr)
{
	skrr->i = 0;
	skrr->j = 0;
	if (skrr->player == 1)
	{
		while (skrr->i < skrr->map_size_x)
		{
			while (skrr->j < skrr->map_size_y)
			{
				
				skrr->j++;
			}
			skrr->i++;
		}
	}
	else if (skrr->player == 2)
	{

	}
}

void	print_info(t_skrr *skrr)
{
	ft_printf("Player: %d\n", skrr->player);
	ft_printf("Map size x:[%d] y:[%d]\n", skrr->map_size_x, skrr->map_size_y);
	skrr->i = -1;
	while (++skrr->i < skrr->map_size_x)
		ft_printf("%s\n", g_map[skrr->i]);
	ft_printf("Piece x:[%d] y:[%d]\n", skrr->piece_size_x, skrr->piece_size_y);
	skrr->j = -1;
	while (++skrr->j < skrr->piece_size_x)
		ft_printf("%s\n", g_piece[skrr->j]);
}
