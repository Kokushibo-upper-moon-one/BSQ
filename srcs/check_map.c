/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stnineta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:10:36 by stnineta          #+#    #+#             */
/*   Updated: 2021/02/08 19:30:41 by stnineta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ch_2_lines(char **map)	//проверка 2х первых строк
{
	char	*chptr;
	int		i;

	chptr = map[0];
	while (*chptr != 0)
		chptr++;
	if (ft_strlen(map[0]) > 3 && *(chptr - 1) >= ' '
		&& *(chptr - 2) >= ' ' && *(chptr - 3) >= ' '
		&& *(chptr - 1) != *(chptr - 2) && *(chptr - 1) != *(chptr - 3)
		&& *(chptr - 2) != *(chptr - 3))
	{
		i = 0;
		while (i < ((chptr - 3) - map[0]))
		{
			if (map[0][i] < '0' || map[0][i] > '9')
				return (0);
			i++;
		}
		if (!map[1] || (map[1][0] != *(chptr - 2) && map[1][0] != *(chptr - 3)))
			return (0);
		return (1);
	}
	else
		return (0);
}

int		ch_nb_lines(char **map, int height)		//прговерка nb срок
{
	char	*nblines;
	int		nblinesint;
	int		i;

	nblines = malloc(ft_strlen(map[0]) - 3);
	i = 0;
	while (i < ft_strlen(map[0]) - 3)
	{
		nblines[i] = map[0][i];
		i++;
	}
	nblines[i] = 0;
	nblinesint = ft_atoi(nblines);
	free(nblines);
	if (nblinesint == height - 1)
		return (1);
	return (0);
}

int		ch_line_len_cons(char **map)	//проверка согласованности длинны строки
{
	int ref_len;
	int i;

	ref_len = ft_strlen(map[1]);
	i = 2;
	while (map[i])
	{
		if (ft_strlen(map[i++]) != ref_len)
			return (0);
	}
	if (map[i - 1][ref_len] != 0)
		return (0);
	return (1);
}

int		ch_chset_cons(char **map)		//проверка согласованности кодировки
{
	char	*chptr;
	int		j;
	int		i;
	char	empty;
	char	obstac;

	chptr = map[0];
	while (*chptr != 0)
		chptr++;
	empty = *(chptr - 3);
	obstac = *(chptr - 2);
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] != empty && map[i][j] != obstac)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**check_map(char **map, int height)
{
	if (!(ch_2_lines(map)))
		return (NULL);
	if (!(ch_nb_lines(map, height)))
		return (NULL);
	if (!(ch_line_len_cons(map)))
		return (NULL);
	if (!(chk_chset_cons(map)))
		return (NULL);
	return (map);
}
