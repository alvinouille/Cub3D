void	deplacement_key(int key_symbole, t_game *game)
{
	t_moh2f	next_pos;
	t_moh2f lol;

	next_pos = game->player_pos;
	if (key_symbole == W)
	{
		next_pos.y -= (game->pd.y * 5);
		next_pos.x -= (game->pd.x * 5);
		lol.x = next_pos.x - 1;
		lol.y = next_pos.y - 1;
	}
	if (key_symbole == S)
	{
		next_pos.y += (game->pd.y * 5);
		next_pos.x += (game->pd.x * 5);
		lol.x = next_pos.x + 1;
		lol.y = next_pos.y + 1;
	}
	if (key_symbole == A)
	{
		next_pos.x -= (game->pd.y * 5) - 1;
		next_pos.y += (game->pd.x * 5) + 1;
		lol.x = next_pos.x - 1;
		lol.y = next_pos.y + 1;
	}
	if (key_symbole == D)
	{
		next_pos.x += (game->pd.y * 5) + 1;
		next_pos.y -= (game->pd.x * 5) - 1;
		lol.x = next_pos.x + 1;
		lol.y = next_pos.y - 1;
	}
	if (!is_wall(game, lol))
		game->player_pos = next_pos;
}