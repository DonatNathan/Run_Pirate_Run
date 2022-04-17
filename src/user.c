/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain function to create user
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../includes/my.h"
#include "../includes/structs.h"
#include <stddef.h>

sfIntRect change_rect(sfIntRect rect)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = 165;
    rect.height = 176;
    return (rect);
}

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    rect.left += offset;
    if (rect.left >= max_value)
        rect.left = 0;
    return (rect);
}

sfIntRect create_clock(sfIntRect rect, int offset, int max_value,
game *my_game)
{
    if (my_game->secs > my_game->cmpt_move) {
        rect = move_rect(rect, offset, max_value);
        my_game->cmpt_move += 15;
    }
    if (my_game->secs >= 200) {
        sfClock_restart(my_game->clock);
        my_game->cmpt_move = 0;
    }
    return (rect);
}

void set_texture(runner *my_pirate, game *my_game)
{
    if (my_game->pirate == 1) {
        my_pirate->t_r = sfTexture_createFromFile("pics/pirate/1/run.png",
        NULL);
        my_pirate->t_j = sfTexture_createFromFile("pics/pirate/1/jump.png",
        NULL);
        my_pirate->t_a = sfTexture_createFromFile\
            ("pics/pirate/1/attack.png", NULL);
    } else if (my_game->pirate == 2) {
        my_pirate->t_r = sfTexture_createFromFile("pics/pirate/2/run.png",
        NULL);
        my_pirate->t_j = sfTexture_createFromFile("pics/pirate/2/jump.png",
        NULL);
        my_pirate->t_a = sfTexture_createFromFile\
            ("pics/pirate/2/attack.png", NULL);
    } else {
        my_pirate->t_r = sfTexture_createFromFile("pics/pirate/3/run.png",
        NULL);
        my_pirate->t_j = sfTexture_createFromFile("pics/pirate/3/jump.png",
        NULL);
        my_pirate->t_a = sfTexture_createFromFile\
            ("pics/pirate/3/attack.png", NULL);
    }
}

runner *create_user(game *my_game)
{
    runner *my_pirate = malloc(sizeof(runner));
    sfVector2f position = {150, 800};
    sfVector2f scale = {1, 1};

    my_pirate->position.x = position.x;
    my_pirate->position.y = position.y;
    set_texture(my_pirate, my_game);
    my_pirate->s_runner = sfSprite_create();
    sfSprite_setTexture(my_pirate->s_runner, my_pirate->t_r, sfFalse);
    sfSprite_setPosition(my_pirate->s_runner, my_pirate->position);
    sfSprite_setScale(my_pirate->s_runner, scale);
    my_pirate->rect = change_rect(my_pirate->rect);
    return (my_pirate);
}
