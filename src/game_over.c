/*
** EPITECH PROJECT, 2022
** MY_RUNNER
** File description:
** It's the file that contain functions to draw the end game menu
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>
#include "../includes/structs.h"
#include <stdlib.h>

endgame *set_end(endgame *my_end)
{
    sfVector2f position = {300, 50};
    sfVector2f scale = {3.8, 3};

    sfSprite_setPosition(my_end->my_back, position);
    sfSprite_setScale(my_end->my_back, scale);
    return (my_end);
}

endgame *create_end(s_pause *my_pause, int win)
{
    endgame *my_end = malloc(sizeof(endgame));
    sfVector2f pos_quit = {1000, 375};
    sfVector2f pos_restart = {400, 375};
    sfVector2f scale = {0.5, 0.5};

    my_end->back = sfTexture_createFromFile("pics/end.png", NULL);
    my_end->button = sfTexture_createFromFile("pics/button.png", NULL);
    my_end->s_quit = sfSprite_create();
    my_end->s_restart = sfSprite_create();
    my_end->my_back = sfSprite_create();
    sfSprite_setTexture(my_end->s_quit, my_end->button, sfFalse);
    sfSprite_setTexture(my_end->s_restart, my_end->button, sfFalse);
    sfSprite_setPosition(my_end->s_quit, pos_quit);
    sfSprite_setPosition(my_end->s_restart, pos_restart);
    sfSprite_setScale(my_end->s_quit, scale);
    sfSprite_setScale(my_end->s_restart, scale);
    sfSprite_setTexture(my_end->my_back, my_end->back, sfFalse);
    my_end = create_text2(my_pause, win, my_end);
    my_end = set_end(my_end);
    return (my_end);
}

endgame *check_mouse(endgame *my_end, game *my_game, sounds *my_sounds, \
                     s_pause *my_pause)
{
    sfVector2i mouse_position = sfMouse_getPosition((sfWindow *) my_game->window);
    sfVector2f pos_quit = sfSprite_getPosition(my_end->s_quit);
    sfVector2f pos_restart = sfSprite_getPosition(my_end->s_restart);

    if (mouse_position.x > pos_quit.x && mouse_position.x < \
pos_quit.x + 460 && mouse_position.y > pos_quit.y \
        && mouse_position.y < pos_quit.y + 190) {
        sfText_setColor(my_end->quit, sfWhite);
        if (my_game->event.type == sfEvtMouseButtonReleased)
            sfRenderWindow_close(my_game->window);
    } else if (mouse_position.x > pos_restart.x && mouse_position.x <    \
pos_restart.x + 460 && mouse_position.y > pos_restart.y \
               && mouse_position.y < pos_restart.y + 190) {
        sfText_setColor(my_end->restart, sfWhite);
        if (my_game->event.type == sfEvtMouseButtonReleased)
            play_game(my_pause, my_game, my_sounds);
    } else {
        sfText_setColor(my_end->quit, sfBlack);
        sfText_setColor(my_end->restart, sfBlack);
    }
    return (my_end);
}

endgame *check_end(endgame *my_end, game *my_game, s_pause *my_pause, \
                   sounds *my_sounds)
{
    while (sfRenderWindow_pollEvent(my_game->window, &my_game->event)) {
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(my_game->window);
        if (sfKeyboard_isKeyPressed(sfKeyR))
            play_game(my_pause, my_game, my_sounds);
        my_end = check_mouse(my_end, my_game, my_sounds, my_pause);
    }
    return (my_end);
}

void game_stop(game *my_game, s_pause *my_pause, int win)
{
    endgame *my_end = create_end(my_pause, win);

    my_game->life = my_pause->life;
    my_pause = change_button(my_pause);
    if (win == 0)
        sfSound_play(my_game->my_s->win);
    else
    sfSound_play(my_game->my_s->lose);
    while (sfRenderWindow_isOpen(my_game->window)) {
        draw_end(my_game, my_end);
        sfRenderWindow_display(my_game->window);
        check_end(my_end, my_game, my_pause, my_game->my_s);
    }
}
