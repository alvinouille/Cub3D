/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:03:50 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/14 16:40:58 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_x(t_game *game)
{
	fprintf(stderr, "FIN DU JEUX AVEC LA CROIX\n");
	mlx_loop_end(game->mlx);
	exit (0);
	return (1);
}

void	modify(t_game *game)
{
	char	**tab;
	int		i;
	int		size;

	size = 0;
	i = 0;
	int j = 0;
	tab = NULL;
	while (game->tab[i])
	{
		while (game->tab[i][j])
			j++;
		if (j > size)
			size = j;
		j = 0;
		i++;
	}
	game->map_size[0] = i - 1;
	game->map_size[1] = size - 1;
	i = 1;
	j = 1;
	tab = malloc((sizeof(char *) * (game->map_size[0] + 1)));
	free(game->tab[0]);
	while (i < (int)game->map_size[0])
	{
		tab[i - 1] = malloc(sizeof(char) * game->map_size[1]);
		while (j < (int)game->map_size[1] - 1)
		{
			if (game->tab[i][j] == '\0' || game->tab[i][j] == ' ')
				tab[i - 1][j - 1] = 'X';
			else
				tab[i - 1][j - 1] = game->tab[i][j];
			j++;
		}
		free(game->tab[i]);
		tab[i - 1][j - 1] = 0;
		j = 1;
		i++;
	}
	free(game->tab[i]);
	tab[i - 1] = NULL;
	free(game->tab);
	i = 0;
	j = 0;
	// while (tab[i])
	// 	printf("%s \n", tab[i++]);
	game->tab = tab;
	printf("height : %d, length : %d \n", game->map_size[0], game->map_size[1]);
}
