/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file where we can choose skin and level
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>
#include "../includes/structs.h"
#include <stdlib.h>

void draw_choices(sfRenderWindow *window, choices *my_choices)
{
    sfRenderWindow_drawSprite(window, my_choices->black, sfFalse);
    sfRenderWindow_drawSprite(window, my_choices->white, sfFalse);
    sfRenderWindow_drawSprite(window, my_choices->woman, sfFalse);
    sfRenderWindow_drawSprite(window, my_choices->button1, sfFalse);
    sfRenderWindow_drawSprite(window, my_choices->button2, sfFalse);
    sfRenderWindow_drawText(window, my_choices->level1, sfFalse);
    sfRenderWindow_drawText(window, my_choices->level2, sfFalse);
    sfRenderWindow_drawText(window, my_choices->selection, sfFalse);
}

void create_select(choices *my_choices)
{
    sfVector2f scale = {3, 3};
    sfVector2f position = {580, 350};

    my_choices->rect = change_rect(my_choices->rect);
    my_choices->pos_selection = position;
    sfText_setFont(my_choices->selection, my_choices->font);
    sfText_setString(my_choices->selection, "/\\");
    sfText_setScale(my_choices->selection, scale);
    sfText_setPosition(my_choices->selection, my_choices->pos_selection);
}

choices *skin_choice(game *my_game, choices *my_choices, sfVector2i mouse_pos)
{
    if (mouse_pos.x > my_choices->pos_black.x && mouse_pos.x <
    (my_choices->pos_black.x + 165) && mouse_pos.y > my_choices->pos_black.y
    && mouse_pos.y < (my_choices->pos_black.y + 165)) {
        if (my_game->event.type == sfEvtMouseButtonReleased) {
            my_game->pirate = 3;
            my_choices->pos_selection.x = 580;
            sfText_setPosition(my_choices->selection,
            my_choices->pos_selection);
        }
    }
    if (mouse_pos.x > my_choices->pos_woman.x && mouse_pos.x <
    (my_choices->pos_woman.x + 165) && mouse_pos.y > my_choices->pos_woman.y
    && mouse_pos.y < (my_choices->pos_woman.y + 165)) {
        if (my_game->event.type == sfEvtMouseButtonReleased) {
            my_game->pirate = 2;
            my_choices->pos_selection.x	= 1280;
            sfText_setPosition(my_choices->selection,
            my_choices->pos_selection);
        }
    }
    if (mouse_pos.x > my_choices->pos_white.x && mouse_pos.x <
    (my_choices->pos_white.x + 165) && mouse_pos.y > my_choices->pos_white.y
    && mouse_pos.y < (my_choices->pos_white.y + 165)) {
        if (my_game->event.type == sfEvtMouseButtonReleased) {
            my_game->pirate = 1;
            my_choices->pos_selection.x	= 930;
            sfText_setPosition(my_choices->selection,
            my_choices->pos_selection);
        }
    }
    return (my_choices);
}

void check_event_choices(s_pause *my_pause, game *my_game, \
choices *my_choices, sounds *my_sounds)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) \
    my_game->window);

    while (sfRenderWindow_pollEvent(my_game->window, &my_game->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
            my_game->level = 1;
            play_game(my_pause, my_game, my_game->my_s);
        }
        if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
            my_game->level = 2;
            play_game(my_pause, my_game, my_game->my_s);
        }
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            open_menu(my_game->window, my_game->life, 0);
        my_choices = skin_choice(my_game, my_choices, mouse_pos);
        change_level(my_game, my_choices, mouse_pos, my_pause);
    }
}

void choose_lvl_skin(game *my_game, s_pause *my_pause, sounds *my_sounds)
{
    choices *my_choices = create_choices();

    my_game->my_s = my_sounds;
    while (sfRenderWindow_isOpen(my_game->window)) {
        update_game(my_game);
        sfRenderWindow_clear(my_game->window, sfBlack);
        my_choices->rect = create_clock(my_choices->rect, 165, 1155, my_game);
        check_event_choices(my_pause, my_game, my_choices, my_sounds);
        sfSprite_setTextureRect(my_choices->black, my_choices->rect);
        sfSprite_setTextureRect(my_choices->white, my_choices->rect);
        sfSprite_setTextureRect(my_choices->woman, my_choices->rect);
        draw_choices(my_game->window, my_choices);
        sfRenderWindow_display(my_game->window);
    }
    sfClock_destroy(my_game->clock);
}
