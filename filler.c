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

int 	main(void)
{
	char	*line;
	t_skrr	skrr;
//	int 	fd;

	skrr.sh = -1;
//	fd = open("test.txt", O_WRONLY);
//	fd = open("small_map.txt", O_RDONLY);
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
	{

		skrr->x_map = -1;
		skrr->x_piece = -1;
		skrr->map_size_x = 15;
		skrr->map_size_y = 17;
		g_map = ((char **)malloc((sizeof(char *) * skrr->map_size_x)));
	}
	else if (!(ft_strncmp(*line, "Plateau 24", 10)))
	{
		skrr->x_map = -1;
		skrr->x_piece = -1;
		skrr->map_size_x = 24;
		skrr->map_size_y = 40;
		g_map = ((char **)malloc((sizeof(char *) * skrr->map_size_x)));
	}
	else if (!(ft_strncmp(*line, "Plateau 10", 10)))
	{
		skrr->x_map = -1;
		skrr->x_piece = -1;
		skrr->map_size_x = 100;
		skrr->map_size_y = 99;
		g_map = ((char **)malloc((sizeof(char *) * skrr->map_size_x)));
	}
	(!(ft_strncmp(*line, "Piece", 5))) ? piece_size(line, skrr) : 0;
}

void	found_first(t_skrr *skrr)
{
	skrr->manh = -1;
	skrr->tmp = 100000;
	if (skrr->player == 1)
	{
		skrr->x_map = -1;
		while ((++skrr->x_map < skrr->map_size_x) && ((skrr->x_map + skrr->x_piece) < skrr->map_size_x))
		{
			skrr->y_map = -1;
			while ((++skrr->y_map < skrr->map_size_y) && ((skrr->y_map + skrr->y_piece) < skrr->map_size_y))
			{
				if (find_star(skrr, 'O', 'X'))
				{
					if (skrr->map_size_x == 15)
						path_small(skrr);
					else if (skrr->map_size_x == 24)
						path_medium(skrr);
//					else if (skrr->map_size_x == 99)
//						path_large(skrr);
				}
			}
		}
		ft_printf("%d %d\n", skrr->best_x, skrr->best_y);
		skrr->manh == -1 ? ft_printf("%d %d\n", 0, 0) : 0;
	}
	else if (skrr->player == 2)
	{
		skrr->x_map = -1;
		while ((++skrr->x_map < skrr->map_size_x) && ((skrr->x_map + skrr->x_piece) < skrr->map_size_x))
		{
			skrr->y_map = -1;
			while ((++skrr->y_map < skrr->map_size_y) && ((skrr->y_map + skrr->y_piece) < skrr->map_size_y))
			{
				if (find_star(skrr, 'X', 'O'))
				{
					ft_printf("%d %d\n", skrr->x_map, skrr->y_map);
					return ;
				}
			}
		}
		skrr->manh == -1 ? ft_printf("%d %d\n", 0, 0) : 0;
	}
}

int		find_star(t_skrr *skrr, char o, char x)
{
	int k;
	int n;

	n = 0;
	k = 0;
	skrr->x_piece = -1;
	while ((++skrr->x_piece < skrr->piece_size_x) &&
			((skrr->x_map + skrr->x_piece) < skrr->map_size_x))
	{
		skrr->y_piece = -1;
		while((++skrr->y_piece < skrr->piece_size_y) &&
				((skrr->y_map + skrr->y_piece) < skrr->map_size_y))
		{
			if (g_map[skrr->x_map + skrr->x_piece][skrr->y_map + skrr->y_piece] == o &&
				g_piece[skrr->x_piece][skrr->y_piece] == '*')
				k++;
			if (g_map[skrr->x_map + skrr->x_piece][skrr->y_map + skrr->y_piece] == x &&
				g_piece[skrr->x_piece][skrr->y_piece] == '*')
				n++;
		}
	}
	if ((k == 1) && (n == 0))
		return (1);
	else
		return (0);
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
