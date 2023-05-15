/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:17:26 by alvina            #+#    #+#             */
/*   Updated: 2023/05/15 16:41:14 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	img_destroyer(t_game *game)
{
	if (game->texture[0].img.img)
		mlx_destroy_image(game->mlx, game->texture[0].img.img);
	if (game->texture[1].img.img)
		mlx_destroy_image(game->mlx, game->texture[1].img.img);
	if (game->texture[2].img.img)
		mlx_destroy_image(game->mlx, game->texture[2].img.img);
	if (game->texture[3].img.img)
		mlx_destroy_image(game->mlx, game->texture[3].img.img);
	if (game->win && game->mlx)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	cleaner(t_game *game, int code)
{
	int	i;

	i = 0;
	if (game->tab)
	{
		while (game->tab[i])
			free(game->tab[i++]);
		free(game->tab);
	}
	img_destroyer(game);
	ft_free(game->info_map->map_info, 0);
	ft_free(game->info_map->texture, 0);
	if (code == 3)
		printf("MLX FAILED : Did you try to fool me ?\n");
	exit(code);
}
