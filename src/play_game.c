/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain functions to draw background
*/

#include <SFML/Graphics.h>
#include "../includes/my.h"
#include "../includes/structs.h"
#include <stdlib.h>
#include <stddef.h>

sounds *create_sounds(void)
{
    sounds *my_sounds = malloc(sizeof(sounds));

    my_sounds->music = sfSoundBuffer_createFromFile("sounds/pirate.ogg");
    my_sounds->ambiance = sfSound_create();
    sfSound_setBuffer(my_sounds->ambiance, my_sounds->music);
    my_sounds->m_jump = sfSoundBuffer_createFromFile("sounds/jump.ogg");
    my_sounds->jump = sfSound_create();
    sfSound_setBuffer(my_sounds->jump, my_sounds->m_jump);
    my_sounds->m_punch = sfSoundBuffer_createFromFile("sounds/punch.ogg");
    my_sounds->punch = sfSound_create();
    sfSound_setBuffer(my_sounds->punch, my_sounds->m_punch);
    my_sounds->m_win = sfSoundBuffer_createFromFile("sounds/win.ogg");
    my_sounds->win = sfSound_create();
    sfSound_setBuffer(my_sounds->win, my_sounds->m_win);
    my_sounds->m_lose = sfSoundBuffer_createFromFile("sounds/lose.ogg");
    my_sounds->lose = sfSound_create();
    sfSound_setBuffer(my_sounds->lose, my_sounds->m_lose);
    return (my_sounds);
}

s_pause *create_button_p(s_pause *my_pause)
{
    sfVector2f position = {1800, 20};
    sfVector2f scale = {2, 2};

    my_pause->t_pause_button = \
        sfTexture_createFromFile("pics/pause_button.png", NULL);
    my_pause->t_play_button = \
        sfTexture_createFromFile("pics/play_button.png", NULL);
    my_pause->pause_button = sfSprite_create();
    sfSprite_setTexture(my_pause->pause_button, my_pause->t_pause_button, \
                        sfFalse);
    sfSprite_setPosition(my_pause->pause_button, position);
    sfSprite_setScale(my_pause->pause_button, scale);
    my_pause->type_button = 1;
    return (my_pause);
}

game *check_event_game(game *my_game, s_pause *my_pause, runner *my_pirate, \
map *my_map)
{
    sfVector2i mouse_position = sfMouse_getPosition((sfWindow *) \
    my_game->window);

    while (sfRenderWindow_pollEvent(my_game->window, &my_game->event)) {
        if (my_game->event.type == sfEvtClosed)
            sfRenderWindow_close(my_game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) || (mouse_position.x > 1800 \
&& mouse_position.x <= 1890 && mouse_position.y > 20 && mouse_position.y <= \
110 && my_game->event.type == sfEvtMouseButtonReleased))
            pause_menu(my_game, my_pause);
        if (sfKeyboard_isKeyPressed(sfKeyUp) && my_game->action == 0) {
            sfSound_play(my_game->my_s->jump);
            my_game = jump(my_pirate, my_game);
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace) && my_game->action == 0) {
            sfSound_play(my_game->my_s->punch);
            my_game = attack(my_pirate, my_game, my_map);
        }
    }
    return (my_game);
}

void check_position(parallax *my_back, sfRenderWindow *window)
{
    sfVector2f base = {0, 0};
    sfVector2f pos_cloud = sfSprite_getPosition(my_back->cloud);
    sfVector2f pos_sea = sfSprite_getPosition(my_back->sea);
    sfVector2f pos_land = sfSprite_getPosition(my_back->land);
    sfVector2f pos_sky = sfSprite_getPosition(my_back->sky);

    if (pos_cloud.x < -1920)
        sfSprite_setPosition(my_back->cloud, base);
    if (pos_sea.x < -3880)
        sfSprite_setPosition(my_back->sea, base);
    if (pos_land.x < -3840)
        sfSprite_setPosition(my_back->land, base);
    if (pos_sky.x < -1920)
        sfSprite_setPosition(my_back->sky, base);
}

int play_game(s_pause *my_pause, game *my_game, sounds *my_sounds)
{
    parallax *my_back = create_parallax(my_game);
    sfText *my_score = create_score();
    runner *my_pirate = create_user(my_game);
    struct map *my_map = create_map();

    change_button(my_pause);
    my_pause->score = 0;
    while (sfRenderWindow_isOpen(my_game->window)) {
        update_play(my_back, my_game, my_pause, my_pirate);
        draw_score(my_score, my_game->window, my_pause->score, my_pause);
        draw_map(my_game, my_map);
        sfRenderWindow_display(my_game->window);
        check_colision(my_game, my_pause, my_map, my_pirate);
        my_game = check_event_game(my_game, my_pause, my_pirate, my_map);
    }
    free(my_back);
    free(my_pirate);
    return (my_pause->score);
}
