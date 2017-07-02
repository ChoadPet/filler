/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:31:57 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/22 18:32:06 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft/src/ft_printf/ft_printf.h"
# include "libft/src/get_next_line/get_next_line.h"
# include "libft/src/libft/libft.h"

char				**g_map;
char 				**g_piece;

typedef struct		s_skrr
{
	int 			sh;
	int 			k;
	int				n;
	int 			manh;
	int 			tmp;
	int				player;
	int 			map_size_x;
	int 			map_size_y;
	int				x_map;
	int 			y_map;
	int 			piece_size_x;
	int 			piece_size_y;
	int 			x_piece;
	int 			y_piece;
	int 			best_x;
	int 			best_y;

}					t_skrr;

void				basic_info(char **line, t_skrr *skrr);
void				map_set(t_skrr *skrr, int x, int y);
void				piece_size(char **line, t_skrr *skrr);
void				found_first(t_skrr *skrr);
void				playing_for_o(t_skrr *skrr);
void				playing_for_x(t_skrr *skrr);
int					find_star(t_skrr *skrr, char o, char x);
void				path_small(t_skrr *skrr);
void				path_medium(t_skrr *skrr);
void				path_large(t_skrr *skrr);
void				fck_best_coordinate(t_skrr *skrr, int x, int y);
int					is_it_free(int x, int y, char c, char cc);

//tmp function, just for print some info
//void				print_info(t_skrr *skrr);

#endif
