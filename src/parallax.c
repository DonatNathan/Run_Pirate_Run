/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain function to create my parallax
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stddef.h>
#include "../includes/my.h"
#include "../includes/structs.h"

parallax *create_parallax(game *my_game)
{
    parallax *my_back = malloc(sizeof(parallax));

    if (my_game->level == 1) {
        my_back->sky = create_object("pics/ground2/sky.png");
        my_back->cloud = create_object("pics/ground2/cloud.png");
        my_back->sea = create_object("pics/ground2/sea.png");
        my_back->land = create_object("pics/ground2/sand.png");
    } else {
        my_back->sky = create_object("pics/ground4/soleil.png");
        my_back->cloud = create_object("pics/ground4/truc.png");
        my_back->sea = create_object("pics/ground4/sea.png");
        my_back->land = create_object("pics/ground4/land.png");
    }
    my_back->s_sky = 20;
    my_back->s_cloud = 10;
    my_back->s_sea = 20;
    my_back->s_land = 80;
    return (my_back);
}

sfVector2f move_back(int speed)
{
    sfVector2f movement = {speed * -0.1, 0};
    return (movement);
}

void draw_parallax(parallax *my_back, sfRenderWindow *window)
{
    sfSprite_move(my_back->sky, move_back(my_back->s_sky));
    sfSprite_move(my_back->cloud, move_back(my_back->s_cloud));
    sfSprite_move(my_back->sea, move_back(my_back->s_sea));
    sfSprite_move(my_back->land, move_back(my_back->s_land));
    sfRenderWindow_drawSprite(window, my_back->sky, sfFalse);
    sfRenderWindow_drawSprite(window, my_back->cloud, sfFalse);
    sfRenderWindow_drawSprite(window, my_back->sea, sfFalse);
    sfRenderWindow_drawSprite(window, my_back->land, sfFalse);
}

sfText *create_score(void)
{
    sfFont *font = sfFont_createFromFile("pics/rockstar.otf");
    sfText *score = sfText_create();
    sfVector2f position = {50, 20};
    sfVector2f scale = {1, 1};

    sfText_setFont(score, font);
    sfText_setPosition(score, position);
    sfText_setScale(score, scale);
    sfText_setColor(score, sfBlack);
    return (score);
}

void draw_score(sfText *my_score, sfRenderWindow *window, int score, \
                s_pause *my_pause)
{
    sfText_setString(my_score, my_itoa(score));
    sfRenderWindow_drawText(window, my_score, sfFalse);
    sfRenderWindow_drawSprite(window, my_pause->pause_button, sfFalse);
}
