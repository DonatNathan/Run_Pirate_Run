/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that create sprites to choose your level
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>
#include "../includes/structs.h"
#include <stdlib.h>

sfText *create_text_level(char *pathname, sfVector2f position)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("pics/rockstar.otf");

    sfText_setFont(text, font);
    sfText_setString(text, pathname);
    sfText_setPosition(text, position);
    return (text);
}

void create_text_button(choices *my_choices)
{
    sfVector2f pos_button1 = {330, 600};
    sfVector2f pos_button2 = {1100, 600};
    sfVector2f pos_level1 = {440, 640};
    sfVector2f pos_level2 = {1210, 640};
    sfVector2f scale_button = {0.5, 0.5};
    sfVector2f scale_text = {3, 3};

    my_choices->pos_button1 = pos_button1;
    my_choices->pos_button2 = pos_button2;
    my_choices->pos_level1 = pos_level1;
    my_choices->pos_level2 = pos_level2;
    sfSprite_setPosition(my_choices->button1, my_choices->pos_button1);
    sfSprite_setPosition(my_choices->button2, my_choices->pos_button2);
    sfSprite_setScale(my_choices->button1, scale_button);
    sfSprite_setScale(my_choices->button2, scale_button);
    my_choices->level1 = create_text_level("LEVEL 1", my_choices->pos_level1);
    my_choices->level2 = create_text_level("LEVEL 2", my_choices->pos_level2);
    sfText_setScale(my_choices->level1, scale_text);
    sfText_setScale(my_choices->level2, scale_text);
    my_choices->font = sfFont_createFromFile("pics/rockstar.otf");
}

choices *create_choices(void)
{
    choices *my_choices = malloc(sizeof(choices));
    sfVector2f pos_black = {550, 200};
    sfVector2f pos_white = {900, 200};
    sfVector2f pos_woman = {1250, 200};

    my_choices->pos_black = pos_black;
    my_choices->selection = sfText_create();
    my_choices->pos_white = pos_white;
    my_choices->pos_woman = pos_woman;
    my_choices->black = create_object("pics/pirate/3/run.png");
    my_choices->white = create_object("pics/pirate/1/run.png");
    my_choices->woman = create_object("pics/pirate/2/run.png");
    sfSprite_setPosition(my_choices->black, pos_black);
    sfSprite_setPosition(my_choices->white, pos_white);
    sfSprite_setPosition(my_choices->woman, pos_woman);
    my_choices->button1 = create_object("pics/button.png");
    my_choices->button2 = create_object("pics/button.png");
    create_text_button(my_choices);
    create_select(my_choices);
    return (my_choices);
}

void change_level(game *my_game, choices *my_choices, sfVector2i mouse_pos, \
                  s_pause *my_pause)
{
    if (mouse_pos.x > my_choices->pos_button1.x && mouse_pos.x < (my_choices->pos_button1.x + 470) && mouse_pos.y > my_choices->pos_button1.y && mouse_pos.y < (my_choices->pos_button1.y + 200)) {
        my_choices->color_button1 = sfWhite;
        sfText_setColor(my_choices->level1, my_choices->color_button1);
        if (my_game->event.type == sfEvtMouseButtonReleased) {
            my_game->level = 1;
            play_game(my_pause, my_game, my_game->my_s);
        }
    } else if (mouse_pos.x > my_choices->pos_button2.x && mouse_pos.x < (my_choices->pos_button2.x + 470) && mouse_pos.y > my_choices->pos_button2.y && mouse_pos.y < (my_choices->pos_button2.y + 200)) {
        my_choices->color_button2 = sfWhite;
        sfText_setColor(my_choices->level2, my_choices->color_button2);
        if (my_game->event.type == sfEvtMouseButtonReleased) {
            my_game->level = 2;
            play_game(my_pause, my_game, my_game->my_s);
	}
    } else {
        my_choices->color_button1 = sfBlack;
        my_choices->color_button2 = sfBlack;
        sfText_setColor(my_choices->level1, my_choices->color_button1);
        sfText_setColor(my_choices->level2, my_choices->color_button2);
    }
}
