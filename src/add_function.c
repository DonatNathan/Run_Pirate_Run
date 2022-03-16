/*
** EPITECH PROJECT, 2022
** MY_RUNNER
** File description:
** It's the file that contain others functions
*/

#include <SFML/Graphics.h>
#include "../includes/my.h"
#include "../includes/structs.h"

void update_play(parallax *my_back, game *my_game, s_pause *my_pause, \
                 runner *my_pirate)
{
    update_game(my_game);
    my_pause->score += 1;
    check_position(my_back, my_game->window);
    sfRenderWindow_clear(my_game->window, sfBlack);
    draw_parallax(my_back, my_game->window);
    my_pirate->rect = create_clock(my_pirate->rect, 165, 1155, my_game);
    sfSprite_setTextureRect(my_pirate->s_runner, my_pirate->rect);
    test_action(my_pirate, my_game);
    sfRenderWindow_drawSprite(my_game->window, my_pirate->s_runner, NULL);
}
