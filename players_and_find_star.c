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

void	found_first(t_skrr *skrr)
{
	skrr->manh = -1;
	skrr->tmp = 100000;
	if (skrr->player == 1)
		playing_for_o(skrr);
	else if (skrr->player == 2)
		playing_for_x(skrr);
}

void	playing_for_o(t_skrr *skrr)
{
	skrr->x_map = -1;
	while ((++skrr->x_map < skrr->map_size_x) &&
			((skrr->x_map + skrr->x_piece) <= skrr->map_size_x))
	{
		skrr->y_map = -1;
		while ((++skrr->y_map < skrr->map_size_y) &&
				((skrr->y_map + skrr->y_piece) <= skrr->map_size_y))
		{
			if (find_star(skrr, 'O', 'X'))
			{
				if (skrr->map_size_x == 15)
					path_small(skrr);
				else if (skrr->map_size_x == 24)
					path_medium(skrr);
				else if (skrr->map_size_x == 100)
					path_large(skrr);
			}
		}
	}
	(skrr->manh != -1) ? ft_printf("%d %d\n", skrr->best_x, skrr->best_y) :
	ft_printf("%d %d\n", 0, 0);
}

void	playing_for_x(t_skrr *skrr)
{
	skrr->x_map = -1;
	while ((++skrr->x_map < skrr->map_size_x) &&
			((skrr->x_map + skrr->x_piece) <= skrr->map_size_x))
	{
		skrr->y_map = -1;
		while ((++skrr->y_map < skrr->map_size_y) &&
				((skrr->y_map + skrr->y_piece) <= skrr->map_size_y))
		{
			if (find_star(skrr, 'X', 'O'))
			{
				if (skrr->map_size_x == 15)
					path_small(skrr);
				else if (skrr->map_size_x == 24)
					path_medium(skrr);
				else if (skrr->map_size_x == 100)
					path_large(skrr);
			}
		}
	}
	(skrr->manh != -1) ? ft_printf("%d %d\n", skrr->best_x, skrr->best_y) :
	ft_printf("0 0\n");
}

int		find_star(t_skrr *skrr, char o, char x)
{
	skrr->n = 0;
	skrr->k = 0;
	skrr->x_piece = -1;
	while ((++skrr->x_piece < skrr->piece_size_x) &&
		   ((skrr->x_map + skrr->x_piece) < skrr->map_size_x))
	{
		skrr->y_piece = -1;
		while((++skrr->y_piece < skrr->piece_size_y) &&
			  ((skrr->y_map + skrr->y_piece) <= skrr->map_size_y))
		{
			if (g_map[skrr->x_map + skrr->x_piece][skrr->y_map + skrr->y_piece] == o &&
				g_piece[skrr->x_piece][skrr->y_piece] == '*')
				skrr->k++;
			if (g_map[skrr->x_map + skrr->x_piece][skrr->y_map + skrr->y_piece] == x &&
				g_piece[skrr->x_piece][skrr->y_piece] == '*')
				skrr->n++;
		}
	}
	if ((skrr->k == 1) && (skrr->n == 0))
		return (1);
	else
		return (0);
}

int		is_it_free(int x, int y, char c, char cc)
{
	if (g_map[x][y] == c || g_map[x][y] == cc)
		return (0);
	else
		return (1);
}