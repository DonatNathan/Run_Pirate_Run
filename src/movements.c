/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain all movement functions
*/

#include <SFML/Graphics.h>
#include "../includes/my.h"
#include "../includes/structs.h"
#include <stdlib.h>
#include <stddef.h>

void test_action(runner *my_pirate, game *my_game)
{
    sfVector2f attack = {1, 0};
    sfVector2f attack2 = {-1, 0};

    if (my_game->action == 1) {
        if (my_pirate->jump.y < 24) {
            my_pirate->jump.y += 1;
            sfSprite_move(my_pirate->s_runner, my_pirate->jump);
        }
    } else if (my_game->action == 2) {
        if (my_game->secs <= 100)
            sfSprite_move(my_pirate->s_runner, attack);
        else
            sfSprite_move(my_pirate->s_runner, attack2);
    }
    if (my_game->secs >= 200)
        my_game = run(my_pirate, my_game);
}

game *run(runner *my_pirate, game *my_game)
{
    sfSprite_setTexture(my_pirate->s_runner, my_pirate->t_r, sfFalse);
    my_game->time_action = 0;
    my_game->action = 0;
    return (my_game);
}

game *jump(runner *my_pirate, game *my_game)
{
    sfVector2f my_jump = {0, -25};

    my_pirate->jump = my_jump;
    sfClock_restart(my_game->clock);
    my_game->time = sfClock_getElapsedTime(my_game->clock);
    my_game->secs = my_game->time.microseconds / 5000.0;
    my_game->time_action = my_game->secs;
    sfSprite_setTexture(my_pirate->s_runner, my_pirate->t_j, sfFalse);
    my_pirate->rect.left = 0;
    my_game->action = 1;
    return (my_game);
}

game *attack(runner *my_pirate, game *my_game, map *my_map)
{
    sfClock_restart(my_game->clock);
    my_game->time = sfClock_getElapsedTime(my_game->clock);
    my_game->secs = my_game->time.microseconds / 5000.0;
    my_game->time_action = my_game->secs;
    sfSprite_setTexture(my_pirate->s_runner, my_pirate->t_a, sfFalse);
    destroy_enemy(my_pirate, my_game, my_map);
    my_pirate->rect.left = 0;
    my_game->action = 2;
    return (my_game);
}
