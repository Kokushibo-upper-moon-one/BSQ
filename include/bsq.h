/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stnineta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:34:23 by stnineta          #+#    #+#             */
/*   Updated: 2021/02/08 11:16:32 by stnineta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	grid_info {
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	sqrchr;
	char	**map;
	int		x_bsq;
	int		y_bsq;
}				grid_info;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			error(char *err);
int				ft_atoi(char *str);

char			**check_map(char **map, int height);

char			**get_lines_from_grid(char *path_to_dict);
int				get_number_of_lines(char **lines);
char			*ft_file_missing(void);

void			square(grid_info mygrid);

char			**split(char *str, char *charset);

#endif
