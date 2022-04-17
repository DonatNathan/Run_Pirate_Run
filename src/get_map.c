/*
** EPITECH PROJECT, 2022
** MY_RUNNER
** File description:
** It's the file that contain function to get and draw the map
*/

#include "../includes/my.h"
#include "SFML/Graphics.h"
#include "../includes/structs.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *get_map(map *my_map)
{
    char buffer[541];
    struct stat st;
    int file_desc = open("map", O_RDONLY);
    char *map;
    int size;

    stat("map", &st);
    map = malloc(sizeof(char) * st.st_size);
    read(file_desc, buffer, st.st_size);
    for (int cmpt = 0; cmpt < st.st_size; cmpt += 1)
        map[cmpt] = buffer[cmpt];
    for (size = 0; buffer[size] != '\n'; size += 1);
    my_map->size = size + 1;
    close(file_desc);
    return (map);
}

cible *check_map(map *my_map, char *map, cible *my_cible, int *is_finded)
{
    int pos = my_map->cmpt_y * my_map->size + my_map->cmpt_x;
    sfVector2f position;

    position.x = 2000;
    position.y = (my_map->cmpt_y + 1) * 200;
    if (map[pos] != ' ') {
        my_cible = check_sprite(pos, my_cible, my_map, position);
        *is_finded = 0;
    }
    return (my_cible);
}

cible *walk_in_map(map *my_map, char *map, cible *my_cible)
{
    int obstacle_finded = 1;
    int *is_finded = &obstacle_finded;

    for (; my_map->cmpt_x < my_map->size && obstacle_finded == 1; \
    my_map->cmpt_x += 1) {
        for (my_map->cmpt_y = 0; my_map->cmpt_y < 4 && obstacle_finded == 1; \
        my_map->cmpt_y += 1) {
            my_cible = check_map(my_map, map, my_cible, is_finded);
        }
    }
    return (my_cible);
}

map *create_map(void)
{
    struct map *my_map = malloc(sizeof(struct map));

    my_map->map = get_map(my_map);
    my_map->s1 = malloc(sizeof(cible));
    my_map->s2 = malloc(sizeof(cible));
    my_map->s3 = malloc(sizeof(cible));
    my_map->s4 = malloc(sizeof(cible));
    my_map = create_enemy(my_map);
    my_map->cmpt_x = 0;
    my_map->s1 = walk_in_map(my_map, my_map->map, my_map->s1);
    my_map->s2 = walk_in_map(my_map, my_map->map, my_map->s2);
    my_map->s3 = walk_in_map(my_map, my_map->map, my_map->s3);
    my_map->s4 = walk_in_map(my_map, my_map->map, my_map->s4);
    return (my_map);
}

void draw_map(game *my_game, map *my_map)
{
    my_map = refresh_sprite(my_map, my_map->map);
    sfSprite_move(my_map->s1->sprite, my_map->s1->speed);
    sfSprite_move(my_map->s2->sprite, my_map->s2->speed);
    sfSprite_move(my_map->s3->sprite, my_map->s3->speed);
    sfSprite_move(my_map->s4->sprite, my_map->s4->speed);
    sfRenderWindow_drawSprite(my_game->window, my_map->s1->sprite, sfFalse);
    sfRenderWindow_drawSprite(my_game->window, my_map->s2->sprite, sfFalse);
    sfRenderWindow_drawSprite(my_game->window, my_map->s3->sprite, sfFalse);
    sfRenderWindow_drawSprite(my_game->window, my_map->s4->sprite, sfFalse);
}
