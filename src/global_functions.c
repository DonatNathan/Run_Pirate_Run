/*
** EPITECH PROJECT, 2021
** MY_RUNNER
** File description:
** It's the file that countain different functions
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>
#include "../includes/structs.h"

sfSprite *create_object(char *pathname)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(pathname, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

game_menu *create_title(game_menu *my_menu)
{
    sfFont *font = sfFont_createFromFile("pics/SuperMario256.ttf");
    sfVector2f scale = {5, 5};
    sfVector2f position = {470, 800};

    my_menu->my_runner = sfText_create();
    sfText_setFont(my_menu->my_runner, font);
    sfText_setString(my_menu->my_runner, "MY RUNNER");
    sfText_setScale(my_menu->my_runner, scale);
    sfText_setPosition(my_menu->my_runner, position);
    sfText_setColor(my_menu->my_runner, sfBlack);
    return (my_menu);
}

game_menu *color_button(game_menu *my_menu, sfVector2i mouse_position)
{
    if (mouse_position.x > my_menu->pose_button_p.x && mouse_position.x < \
my_menu->pose_button_p.x + 460 && mouse_position.y > my_menu->pose_button_p.y \
        && mouse_position.y < my_menu->pose_button_p.y + 190) {
        my_menu->color_p = sfWhite;
        sfText_setColor(my_menu->play, my_menu->color_p);
    } else if (mouse_position.x > my_menu->pose_button_q.x && \
mouse_position.x < my_menu->pose_button_q.x + 460 && mouse_position.y > \
my_menu->pose_button_q.y && mouse_position.y < \
my_menu->pose_button_q.y + 190) {
        my_menu->color_q = sfWhite;
        sfText_setColor(my_menu->quit, my_menu->color_q);
    } else {
        my_menu->color_p = sfBlack;
        my_menu->color_q = sfBlack;
        sfText_setColor(my_menu->play, my_menu->color_p);
        sfText_setColor(my_menu->quit, my_menu->color_q);
    }
    return (my_menu);
}

cible *check_sprite(int pos, cible *my_cible, struct map *my_map, \
sfVector2f position)
{
    if (my_map->map[pos] == '1') {
        my_map->num = 1;
        my_cible = change_sprite(my_cible, my_map->block, position, my_map);
    } if (my_map->map[pos] == '2') {
        my_map->num = 2;
        my_cible = change_sprite(my_cible, my_map->barrel, position, my_map);
    } if (my_map->map[pos] == '3') {
        my_map->num = 3;
        my_cible = change_sprite(my_cible, my_map->seagull, position, my_map);
    } if (my_map->map[pos] == '4') {
        my_map->num = 4;
        my_cible = change_sprite(my_cible, my_map->enemy, position, my_map);
    } if (my_map->map[pos] == '5') {
        position.y = -100;
        my_map->num = 5;
        my_cible = change_sprite(my_cible, my_map->ship, position, my_map);
    }
    return (my_cible);
}
