/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain functions to create buttons
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../includes/my.h"
#include "../includes/structs.h"

s_pause *create_buttons(s_pause *my_pause, sfVector2f scale)
{
    my_pause->pos_continu.x = my_pause->pos_menu.x + 150;
    my_pause->pos_continu.y = my_pause->pos_menu.y + 50;
    my_pause->continu_button = sfSprite_create();
    sfSprite_setTexture(my_pause->continu_button, my_pause->t_button, sfFalse);
    sfSprite_setPosition(my_pause->continu_button, my_pause->pos_continu);
    sfSprite_setScale(my_pause->continu_button, scale);
    my_pause->pos_restart.x = my_pause->pos_menu.x + 150;
    my_pause->pos_restart.y = my_pause->pos_menu.y + 200;
    my_pause->restart_button = sfSprite_create();
    sfSprite_setTexture(my_pause->restart_button, my_pause->t_button, sfFalse);
    sfSprite_setPosition(my_pause->restart_button, my_pause->pos_restart);
    sfSprite_setScale(my_pause->restart_button, scale);
    my_pause->pos_quit.x = my_pause->pos_menu.x + 150;
    my_pause->pos_quit.y = my_pause->pos_menu.y + 350;
    my_pause->quit_button = sfSprite_create();
    sfSprite_setTexture(my_pause->quit_button, my_pause->t_button, sfFalse);
    sfSprite_setPosition(my_pause->quit_button, my_pause->pos_quit);
    sfSprite_setScale(my_pause->quit_button, scale);
    return (my_pause);
}

s_pause *create_texts(s_pause *my_pause, sfVector2f pos_c, sfVector2f pos_r, \
                    sfVector2f pos_q)
{
    sfFont *font = sfFont_createFromFile("pics/rockstar.otf");
    sfVector2f scale = {2, 2};

    my_pause->continu = sfText_create();
    sfText_setFont(my_pause->continu, font);
    sfText_setString(my_pause->continu, "CONTINUE (C)");
    sfText_setPosition(my_pause->continu, pos_c);
    sfText_setScale(my_pause->continu, scale);
    my_pause->restart = sfText_create();
    sfText_setFont(my_pause->restart, font);
    sfText_setString(my_pause->restart, "RESTART (R)");
    sfText_setPosition(my_pause->restart, pos_r);
    sfText_setScale(my_pause->restart, scale);
    my_pause->quit = sfText_create();
    sfText_setFont(my_pause->quit, font);
    sfText_setString(my_pause->quit, "MENU (M)");
    sfText_setPosition(my_pause->quit, pos_q);
    sfText_setScale(my_pause->quit, scale);
    return (my_pause);
}

s_pause *remove_pause(s_pause *my_pause, int *ptr_pause)
{
    *ptr_pause = 1;
    my_pause = change_button(my_pause);
    return (my_pause);
}

s_pause *select_button(s_pause *my_pause, sfVector2i mouse_position, \
int *ptr_pause, game *my_game)
{
    if (mouse_position.x > my_pause->pos_continu.x && mouse_position.x <= \
    (my_pause->pos_continu.x + 460) && mouse_position.y >
    my_pause->pos_continu.y && mouse_position.y <=
    (my_pause->pos_continu.y + 130)) {
        my_pause->color_c = sfWhite;
        if (my_game->event.type == sfEvtMouseButtonReleased)
            my_pause = remove_pause(my_pause, ptr_pause);
    } else if (mouse_position.x > my_pause->pos_restart.x && mouse_position.x \
    <= (my_pause->pos_restart.x + 460) && mouse_position.y > \
    my_pause->pos_restart.y && mouse_position.y <= \
    (my_pause->pos_restart.y + 130)) {
        my_pause->color_r = sfWhite;
        if (my_game->event.type == sfEvtMouseButtonReleased)
            play_game(my_pause, my_game, my_game->my_s);
    } else {
        my_pause->color_q = sfWhite;
        if (my_game->event.type == sfEvtMouseButtonReleased)
            open_menu(my_game->window, my_game->life, 0);
    }
    return (my_pause);
}

s_pause *color_buttons(s_pause *my_pause, sfVector2i mouse_position, \
int *ptr_pause, game *my_game)
{
    if ((mouse_position.x > my_pause->pos_quit.x && mouse_position.x <= \
(my_pause->pos_quit.x + 460) && mouse_position.y > my_pause->pos_quit.y && \
mouse_position.y <= (my_pause->pos_quit.y + 130)) || (mouse_position.x > \
my_pause->pos_restart.x && mouse_position.x <= (my_pause->pos_restart.x + 460)
&& mouse_position.y > my_pause->pos_restart.y && mouse_position.y <= \
(my_pause->pos_restart.y + 130)) || (mouse_position.x > \
my_pause->pos_continu.x && mouse_position.x <= (my_pause->pos_continu.x + 460)
&& mouse_position.y > my_pause->pos_continu.y && mouse_position.y <= \
(my_pause->pos_continu.y + 130)))
        my_pause = select_button(my_pause, mouse_position, ptr_pause, my_game);
    else {
        my_pause->color_c = sfBlack;
        my_pause->color_r = sfBlack;
        my_pause->color_q = sfBlack;
    }
    return (my_pause);
}
