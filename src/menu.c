/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain functions to create my menu
*/

#include <SFML/Graphics.h>
#include "../includes/structs.h"
#include <stdlib.h>
#include "../includes/my.h"

void draw_menu(game_menu *my_menu, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, my_menu->background, sfFalse);
    sfRenderWindow_drawSprite(window, my_menu->button_p, sfFalse);
    sfRenderWindow_drawSprite(window, my_menu->button_q, sfFalse);
    sfRenderWindow_drawText(window, my_menu->quit, sfFalse);
    sfRenderWindow_drawText(window, my_menu->play, sfFalse);
    sfRenderWindow_drawText(window, my_menu->my_runner, sfFalse);
}

game_menu *create_text(game_menu *my_menu, sfVector2f position_p, \
                       sfVector2f position_q)
{
    sfFont *font = sfFont_createFromFile("pics/rockstar.otf");
    sfVector2f scale = {3, 3};

    my_menu->quit = sfText_create();
    sfText_setFont(my_menu->quit, font);
    sfText_setString(my_menu->quit, "QUIT (Q)");
    sfText_setPosition(my_menu->quit, position_q);
    sfText_setScale(my_menu->quit, scale);
    my_menu->play = sfText_create();
    sfText_setFont(my_menu->play, font);
    sfText_setString(my_menu->play, "PLAY (P)");
    sfText_setPosition(my_menu->play, position_p);
    sfText_setScale(my_menu->play, scale);
    return (my_menu);
}

game_menu *create_button(game_menu *my_menu)
{
    sfVector2f button_scale = {0.5, 0.5};

    my_menu->pose_button_q.x = 1300;
    my_menu->pose_button_q.y = 100;
    my_menu->pose_button_p.x = 150;
    my_menu->pose_button_p.y = 100;
    my_menu->t_button = sfTexture_createFromFile("pics/button.png", NULL);
    my_menu->button_p = sfSprite_create();
    sfSprite_setTexture(my_menu->button_p, my_menu->t_button, sfFalse);
    sfSprite_setScale(my_menu->button_p, button_scale);
    sfSprite_setPosition(my_menu->button_p, my_menu->pose_button_p);
    my_menu->button_q = sfSprite_create();
    sfSprite_setTexture(my_menu->button_q, my_menu->t_button, sfFalse);
    sfSprite_setScale(my_menu->button_q, button_scale);
    sfSprite_setPosition(my_menu->button_q, my_menu->pose_button_q);
    return (my_menu);
}

game_menu *create_menu(void)
{
    game_menu *my_menu = malloc(sizeof(game_menu));
    sfVector2f b_scale = {2.5, 3};
    sfVector2f position_p;
    sfVector2f position_q;

    my_menu->t_background = sfTexture_createFromFile("pics/ile.png", NULL);
    my_menu->background = sfSprite_create();
    sfSprite_setTexture(my_menu->background, my_menu->t_background, sfFalse);
    sfSprite_setScale(my_menu->background, b_scale);
    my_menu = create_button(my_menu);
    position_q.x = my_menu->pose_button_q.x + 95;
    position_q.y = my_menu->pose_button_q.y + 40;
    position_p.x = my_menu->pose_button_p.x + 95;
    position_p.y = my_menu->pose_button_p.y + 40;
    my_menu = create_text(my_menu, position_p, position_q);
    return (my_menu);
}

game_menu *destroy_menu(game_menu *my_menu)
{
    sfSprite_destroy(my_menu->background);
    sfTexture_destroy(my_menu->t_background);
    sfSprite_destroy(my_menu->button_p);
    sfSprite_destroy(my_menu->button_q);
    sfTexture_destroy(my_menu->t_button);
    sfText_destroy(my_menu->quit);
    sfText_destroy(my_menu->play);
    sfText_destroy(my_menu->my_runner);
    return (my_menu);
}
