/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain pause menu functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../includes/my.h"
#include "../includes/structs.h"

void draw_pause(s_pause *my_pause, sfRenderWindow *window)
{
    sfText_setColor(my_pause->continu, my_pause->color_c);
    sfText_setColor(my_pause->restart, my_pause->color_r);
    sfText_setColor(my_pause->quit, my_pause->color_q);
    sfRenderWindow_drawSprite(window, my_pause->my_menu, sfFalse);
    sfRenderWindow_drawSprite(window, my_pause->continu_button, sfFalse);
    sfRenderWindow_drawSprite(window, my_pause->restart_button, sfFalse);
    sfRenderWindow_drawSprite(window, my_pause->quit_button, sfFalse);
    sfRenderWindow_drawText(window, my_pause->continu, sfFalse);
    sfRenderWindow_drawText(window, my_pause->restart, sfFalse);
    sfRenderWindow_drawText(window, my_pause->quit, sfFalse);
    sfRenderWindow_drawSprite(window, my_pause->pause_button, sfFalse);
}

s_pause *create_pause(game_menu *my_menu)
{
    s_pause *my_pause = malloc(sizeof(s_pause));
    sfVector2f scale = {2, 2};
    sfVector2f button_scale = {0.5, 0.35};

    my_pause->pos_menu.x = 560;
    my_pause->life = my_menu->life;
    my_pause->pos_menu.y = 250;
    my_pause->t_button = sfTexture_createFromFile("pics/button.png", NULL);
    my_pause->t_menu = sfTexture_createFromFile("pics/my_menu.jpg", NULL);
    my_pause->my_menu = sfSprite_create();
    sfSprite_setTexture(my_pause->my_menu, my_pause->t_menu, sfFalse);
    sfSprite_setPosition(my_pause->my_menu, my_pause->pos_menu);
    sfSprite_setScale(my_pause->my_menu, scale);
    my_pause = create_buttons(my_pause, button_scale);
    my_pause = create_button_p(my_pause);
    my_pause->color_c = sfBlack;
    my_pause->color_q =	sfBlack;
    my_pause->color_r =	sfBlack;
    return (my_pause);
}

void check_event_pause(game *my_game, s_pause *my_pause, int *ptr_pause, int time)
{
    sfVector2i mouse_position = sfMouse_getPosition((sfWindow *) \
                                                    my_game->window);

    while (sfRenderWindow_pollEvent(my_game->window, &my_game->event)) {
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        if ((mouse_position.x > 1270 && mouse_position.x <= 1330 && \
mouse_position.y > 270 && mouse_position.y <= 320 && my_game->event.type == \
sfEvtMouseButtonReleased) || (mouse_position.x > 1800 && mouse_position.x <= \
1890 && mouse_position.y > 20 && mouse_position.y <= 110 && my_game->event.type\
== sfEvtMouseButtonReleased) || sfKeyboard_isKeyPressed(sfKeyC) || \
            (sfKeyboard_isKeyPressed(sfKeyEscape) && time != 0))
            my_pause = remove_pause(my_pause, ptr_pause);
        if (sfKeyboard_isKeyPressed(sfKeyR))
            play_game(my_pause, my_game, my_game->my_s);
        if (sfKeyboard_isKeyPressed(sfKeyM))
            open_menu(my_game->window, my_pause->life, 0);
        my_pause = color_buttons(my_pause, mouse_position, ptr_pause, my_game);
    }
}

s_pause *change_button(s_pause *my_pause)
{
    if (my_pause->type_button == 0) {
        my_pause->type_button = 1;
        sfSprite_setTexture(my_pause->pause_button, my_pause->t_play_button, \
                            sfFalse);
    } else {
        my_pause->type_button = 0;
        sfSprite_setTexture(my_pause->pause_button, my_pause->t_pause_button, \
                            sfFalse);
    }
    return (my_pause);
}

void pause_menu(game *my_game, s_pause *my_pause)
{
    int in_pause = 0;
    int *ptr_pause = &in_pause;
    sfVector2f pos_c = {my_pause->pos_continu.x + 80, \
        my_pause->pos_continu.y + 30};
    sfVector2f pos_r = {my_pause->pos_restart.x + 90, \
        my_pause->pos_restart.y + 30};
    sfVector2f pos_q = {my_pause->pos_quit.x + 142, \
        my_pause->pos_quit.y + 30};
    sfVector2i mouse_pause = {1300, 290};
    int time = 0;

    my_pause = change_button(my_pause);
    sfMouse_setPosition(mouse_pause, (sfWindow *) my_game->window);
    my_pause = create_texts(my_pause, pos_c, pos_r, pos_q);
    while (sfRenderWindow_isOpen(my_game->window) && in_pause == 0) {
        draw_pause(my_pause, my_game->window);
        check_event_pause(my_game, my_pause, ptr_pause, time);
        sfRenderWindow_display(my_game->window);
        time += 1;
    }
}
