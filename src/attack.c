/*
** EPITECH PROJECT, 2022
** MY_RUNNER
** File description:
** It's the file that contain function to attack
*/

#include "../includes/my.h"
#include "SFML/Graphics.h"
#include "../includes/structs.h"

void destroy_enemy(runner *my_pirate, game *my_game, map *my_map)
{
    sfVector2f new_position = {-100, 0};
    sfVector2f pos_pirate = sfSprite_getPosition(my_pirate->s_runner);
    sfVector2f pos_s1 = sfSprite_getPosition(my_map->s1->sprite);
    sfVector2f pos_s2 =	sfSprite_getPosition(my_map->s2->sprite);
    sfVector2f pos_s3 =	sfSprite_getPosition(my_map->s3->sprite);
    sfVector2f pos_s4 =	sfSprite_getPosition(my_map->s4->sprite);

    pos_pirate.x += 165;
    if (pos_pirate.x < pos_s1.x && pos_pirate.x > pos_s1.x - 200 && \
        my_map->s1->type == 4)
        sfSprite_setPosition(my_map->s1->sprite, new_position);
    if (pos_pirate.x < pos_s2.x && pos_pirate.x > pos_s2.x - 200 && \
        my_map->s2->type == 4)
        sfSprite_setPosition(my_map->s2->sprite, new_position);
    if (pos_pirate.x < pos_s3.x && pos_pirate.x > pos_s3.x - 200 && \
        my_map->s3->type == 4)
        sfSprite_setPosition(my_map->s3->sprite, new_position);
    if (pos_pirate.x < pos_s4.x && pos_pirate.x > pos_s4.x - 200 && \
        my_map->s4->type == 4)
        sfSprite_setPosition(my_map->s4->sprite, new_position);
}
