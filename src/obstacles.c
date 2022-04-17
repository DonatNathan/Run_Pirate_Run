/*
** EPITECH PROJECT, 2022
** MY_RUNNER
** File description:
** It's the file that coutain function to draw enemys in map
*/

#include "../includes/my.h"
#include "SFML/Graphics.h"
#include "../includes/structs.h"

map *create_enemy(map *my_map)
{
    sfVector2f move = {-20, 0};
    sfVector2f move_barrel = {-8, 0};
    sfIntRect rect;

    my_map->seagull = sfTexture_createFromFile("pics/seagull.png", NULL);
    my_map->barrel = sfTexture_createFromFile("pics/barrel.png", NULL);
    my_map->block = sfTexture_createFromFile("pics/rock.png", NULL);
    my_map->enemy = sfTexture_createFromFile("pics/soldier.png", NULL);
    my_map->ship = sfTexture_createFromFile("pics/pirate_ship.png", NULL);
    my_map->speed_fix = move_barrel;
    my_map->speed_fast = move;
    my_map->rect = change_rect(rect);
    return (my_map);
}

sfSprite *do_sprite(sfTexture *texture, sfVector2f position)
{
    sfSprite *sprite2 = sfSprite_create();

    sfSprite_setTexture(sprite2, texture, sfFalse);
    sfSprite_setPosition(sprite2, position);
    return (sprite2);
}

cible *change_sprite(cible *my_cible, sfTexture *texture, sfVector2f position,
map *my_map)
{
    sfSprite *sprite2 = do_sprite(texture, position);

    if (my_map->num == 1) {
        my_cible->type = 1;
        my_cible->speed = my_map->speed_fix;
    } if (my_map->num == 2) {
        my_cible->type = 2;
        my_cible->speed = my_map->speed_fix;
    } if (my_map->num == 3) {
        my_cible->type = 3;
        my_cible->speed = my_map->speed_fast;
    } if (my_map->num == 4) {
        my_cible->type = 4;
        my_cible->speed = my_map->speed_fix;
    } if (my_map->num == 5) {
        my_cible->type = 5;
        my_cible->speed = my_map->speed_fix;
    }
    my_cible->sprite = sprite2;
    return (my_cible);
}

map *refresh_sprite(map *my_map, char *map)
{
    sfVector2f pos_s1 = sfSprite_getPosition(my_map->s1->sprite);
    sfVector2f pos_s2 = sfSprite_getPosition(my_map->s2->sprite);
    sfVector2f pos_s3 = sfSprite_getPosition(my_map->s3->sprite);
    sfVector2f pos_s4 = sfSprite_getPosition(my_map->s4->sprite);

    if (pos_s1.x <= -100)
        my_map->s1 = walk_in_map(my_map, map, my_map->s1);
    if (pos_s2.x <= -100)
        my_map->s2 = walk_in_map(my_map, map, my_map->s2);
    if (pos_s3.x <= -100)
        my_map->s3 = walk_in_map(my_map, map, my_map->s3);
    if (pos_s4.x <= -100)
        my_map->s4 = walk_in_map(my_map, map, my_map->s4);
    return (my_map);
}

void check_colision(game *my_game, s_pause *my_pause, map *my_map,
runner *my_pirate)
{
    sfVector2f pos_s1 = sfSprite_getPosition(my_map->s1->sprite);
    sfVector2f pos_s2 = sfSprite_getPosition(my_map->s2->sprite);
    sfVector2f pos_s3 = sfSprite_getPosition(my_map->s3->sprite);
    sfVector2f pos_s4 = sfSprite_getPosition(my_map->s4->sprite);

    my_pirate->position = sfSprite_getPosition(my_pirate->s_runner);
    if ((my_pirate->position.x + 130 > pos_s1.x && my_pirate->position.y + 165 > pos_s1.y && my_pirate->position.x + 50 < pos_s1.x + 143 && my_pirate->position.y < pos_s1.y + 100) || (my_pirate->position.x + 130 > pos_s2.x && my_pirate->position.y + 165 > pos_s2.y && my_pirate->position.x + 50 < pos_s2.x + 143 && my_pirate->position.y < pos_s2.y + 100) || (my_pirate->position.x + 130 > pos_s3.x && my_pirate->position.y + 165 > pos_s3.y && my_pirate->position.x + 50 < pos_s3.x + 143 && my_pirate->position.y < pos_s3.y + 100) || (my_pirate->position.x + 130 > pos_s4.x && my_pirate->position.y + 165 > pos_s4.y && my_pirate->position.x + 50 < pos_s4.x + 143 && my_pirate->position.y < pos_s4.y + 100))
        my_game->life -= 10;
    if (my_game->life <= 0) {
        my_game = run(my_pirate, my_game);
        game_stop(my_game, my_pause, 1);
    } else if (my_pause->score >= 1400) {
        my_game = run(my_pirate, my_game);
        game_stop(my_game, my_pause, 0);
    }
}
