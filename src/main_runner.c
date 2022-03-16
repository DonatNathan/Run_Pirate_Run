/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the main file of my program my_runner
*/

#include <SFML/Graphics.h>
#include "../includes/my.h"
#include <stdlib.h>
#include "../includes/structs.h"
#include <stddef.h>

game_menu *check_event_menu(game *my_game, game_menu *my_menu, \
                            sounds *my_sounds, s_pause *my_pause)
{
    sfVector2i mouse_position = sfMouse_getPosition((sfWindow *) \
                                                    my_game->window);

    while (sfRenderWindow_pollEvent(my_game->window, &my_game->event)) {
        if (my_game->event.type == sfEvtClosed || \
sfKeyboard_isKeyPressed(sfKeyQ) || (mouse_position.x > \
my_menu->pose_button_q.x && mouse_position.x < my_menu->pose_button_q.x + \
460 && mouse_position.y > my_menu->pose_button_q.y && mouse_position.y <\
my_menu->pose_button_q.y + 190 && my_game->event.type == \
sfEvtMouseButtonReleased))
            sfRenderWindow_close(my_game->window);
        if (sfKeyboard_isKeyPressed(sfKeyP) || (mouse_position.x > my_menu->\
pose_button_p.x && mouse_position.x < my_menu->pose_button_p.x + 460 && \
mouse_position.y > my_menu->pose_button_p.y && mouse_position.y < my_menu->\
pose_button_p.y + 190 && my_game->event.type == sfEvtMouseButtonReleased)) {
            choose_lvl_skin(my_game, my_pause, my_sounds);
        }
        my_menu = color_button(my_menu, mouse_position);
    }
    return (my_menu);
}

void open_menu(sfRenderWindow *window, int life, int play_music)
{
    sfEvent event;
    game_menu *my_menu = create_menu();
    sfVector2i mouse_start = {960, 540};
    sounds *my_sounds = create_sounds();
    s_pause *my_pause = create_pause(my_menu);
    game *my_game = create_game(window, event, my_pause);

    my_game->life = life;
    my_pause->life = life;
    sfMouse_setPosition(mouse_start, (sfWindow *) window);
    my_menu = create_title(my_menu);
    sfSound_setLoop(my_sounds->ambiance, sfTrue);
    if (play_music == 1)
        sfSound_play(my_sounds->ambiance);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfCyan);
        draw_menu(my_menu, window);
        sfRenderWindow_display(window);
        my_menu = check_event_menu(my_game, my_menu, my_sounds, my_pause);
    }
}

void create_window(char *username)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Runner", \
                                                   sfResize | sfClose, NULL);
    int life;

    if (username[0] == 'J' && username[1] == 'e' && username[2] == 's' && \
        username[3] == 's' && username[4] == 'i' && username[5] == 'c' && \
        username[6] == 'a')
        life = 10000;
    else
        life = 10;
    sfRenderWindow_setFramerateLimit(window, 60);
    open_menu(window, life, 1);
}

void help_menu(void)
{
    my_printf(" ##### MY_RUNNER #####\n\n");
    my_printf("\"You are a pirate king, your goal is to secure your gold \
chest in your ship. But, be carreful, queen Elisabeth want \
this money.\"\n\n");
    my_printf(">>> You can jump with the touch 'Up Arrow'.\n");
    my_printf(">>> You can also attack with the touch 'space'.\n");
    my_printf(">>> If you tap 'Escape' in game, a pause menu \
is launched.\n");
    my_printf(">>> Dodge seagulls, barrels and queen \
Elisabeth's soldiers\n\n");
    my_printf("Now, you can launch the game and safe your treasur \
with the commande \"./my_runner -p <username>\"\n");
    my_printf("Good luck my friend !\n\n");
    my_printf("PS : If the game is too hard, test with the \
username \"Jessica\". ;)\n");
}

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3) {
        my_printf("Invalid number of params\n");
        return (84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        help_menu();
    else if (argv[1][0] == '-' && argv[1][1])
        create_window(argv[2]);
    else {
        my_printf("Invalid params\n");
        return (84);
    }
    return (0);
}
