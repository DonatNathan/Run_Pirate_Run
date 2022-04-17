/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain functions to create my game
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>
#include "../includes/structs.h"
#include <stdlib.h>

game *create_game(sfRenderWindow *window, sfEvent event, \
s_pause *my_pause)
{
    game *my_game = malloc(sizeof(game));

    my_game->my_s = malloc(sizeof(sounds));
    my_game->clock = sfClock_create();
    my_game->window = window;
    my_game->event = event;
    my_game->time_action = 0;
    my_game->cmpt_move = 0;
    my_game->action = 0;
    my_pause->score = 0;
    my_game->pirate = 3;
    return (my_game);
}

void update_game(game *my_game)
{
    my_game->time = sfClock_getElapsedTime(my_game->clock);
    my_game->secs = my_game->time.microseconds / 5000.0;
}

endgame *create_text3(endgame *my_end)
{
    sfVector2f scale_button = {2.5, 2.5};
    sfVector2f scale_text = {4, 4};
    sfVector2f pos_score = {900, 700};
    sfVector2f pos_text = {750, 100};
    sfVector2f pos_quit = {1130, 425};
    sfVector2f pos_restart = {450, 425};

    sfText_setScale(my_end->score, scale_text);
    sfText_setScale(my_end->quit, scale_button);
    sfText_setScale(my_end->restart, scale_button);
    sfText_setScale(my_end->result, scale_text);
    sfText_setPosition(my_end->score, pos_score);
    sfText_setPosition(my_end->quit, pos_quit);
    sfText_setPosition(my_end->restart, pos_restart);
    sfText_setPosition(my_end->result, pos_text);
    sfText_setColor(my_end->result, sfBlack);
    sfText_setColor(my_end->score, sfBlack);
    sfText_setColor(my_end->quit, sfBlack);
    sfText_setColor(my_end->restart, sfBlack);
    return (my_end);
}

endgame *create_text2(s_pause *my_pause, int win, endgame *my_end)
{
    sfFont *font_button = sfFont_createFromFile("pics/rockstar.otf");
    sfFont *font_text = sfFont_createFromFile("pics/SIXTY.TTF");

    my_end->score = sfText_create();
    my_end->quit = sfText_create();
    my_end->restart = sfText_create();
    my_end->result = sfText_create();
    sfText_setFont(my_end->score, font_text);
    sfText_setFont(my_end->quit, font_button);
    sfText_setFont(my_end->restart, font_button);
    sfText_setFont(my_end->result, font_text);
    sfText_setString(my_end->score, my_itoa(my_pause->score));
    sfText_setString(my_end->quit, "QUIT (Q)");
    sfText_setString(my_end->restart, "RESTART (R)");
    if (win == 0)
        sfText_setString(my_end->result, "VICTORY !");
    else
        sfText_setString(my_end->result, "DEFEAT !");
    my_end = create_text3(my_end);
    return (my_end);
}

void draw_end(game *my_game, endgame *my_end)
{
    sfRenderWindow_drawSprite(my_game->window, my_end->my_back, sfFalse);
    sfRenderWindow_drawSprite(my_game->window, my_end->s_quit, sfFalse);
    sfRenderWindow_drawSprite(my_game->window, my_end->s_restart, sfFalse);
    sfRenderWindow_drawText(my_game->window, my_end->score, sfFalse);
    sfRenderWindow_drawText(my_game->window, my_end->quit, sfFalse);
    sfRenderWindow_drawText(my_game->window, my_end->restart, sfFalse);
    sfRenderWindow_drawText(my_game->window, my_end->result, sfFalse);
}
