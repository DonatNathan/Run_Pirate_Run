/*
** EPITECH PROJECT, 2021
** BOOTSTRAP MY_RUNNER
** File description:
** It's the .h of my main_runner.c
*/

#ifndef MAIN_RUNNER_H_
    #define MAIN_RUNNER_H_

    #include <SFML/Audio.h>

typedef struct sounds {
    sfSoundBuffer *music;
    sfSound *ambiance;
    sfSoundBuffer *m_jump;
    sfSound *jump;
    sfSoundBuffer *m_punch;
    sfSound *punch;
    sfSoundBuffer *m_win;
    sfSound *win;
    sfSoundBuffer *m_lose;
    sfSound *lose;
} sounds;

typedef struct choices {
    sfTexture *t_black;
    sfTexture *t_white;
    sfTexture *t_woman;
    sfSprite *black;
    sfSprite *white;
    sfSprite *woman;
    sfVector2f pos_black;
    sfVector2f pos_white;
    sfVector2f pos_woman;
    sfText *level1;
    sfText *level2;
    sfVector2f pos_level1;
    sfVector2f pos_level2;
    sfTexture *button;
    sfSprite *button1;
    sfSprite *button2;
    sfVector2f pos_button1;
    sfVector2f pos_button2;
    sfColor color_button1;
    sfColor color_button2;
    sfIntRect rect;
    sfText *selection;
    sfVector2f pos_selection;
    sfFont *font;
} choices;

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    int secs;
    int action;
    int cmpt_move;
    int time_action;
    int level;
    int pirate;
    int life;
    sounds *my_s;
} game;

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
} game_object;

typedef struct game_menu {
    sfSprite *background;
    sfTexture *t_background;
    sfSprite *button_p;
    sfTexture *t_button;
    sfVector2f pose_button_p;
    sfSprite *button_q;
    sfVector2f pose_button_q;
    sfText *play;
    sfText *quit;
    sfText *my_runner;
    sfColor color_p;
    sfColor color_q;
    int life;
} game_menu;

typedef struct parallax {
    sfSprite *sky;
    sfSprite *cloud;
    sfSprite *sea;
    sfSprite *land;
    int s_sky;
    int s_cloud;
    int s_sea;
    int s_land;
} parallax;

typedef struct s_pause {
    sfTexture *t_menu;
    sfTexture *t_button;
    sfSprite *my_menu;
    sfSprite *quit_button;
    sfSprite *continu_button;
    sfSprite *restart_button;
    sfColor color_q;
    sfColor color_c;
    sfColor color_r;
    sfText *quit;
    sfText *continu;
    sfText *restart;
    sfVector2f pos_menu;
    sfVector2f pos_quit;
    sfVector2f pos_continu;
    sfVector2f pos_restart;
    sfTexture *t_pause_button;
    sfTexture *t_play_button;
    sfSprite *pause_button;
    int type_button;
    int score;
    int life;
} s_pause;

typedef struct runner {
    sfTexture *t_r;
    sfTexture *t_j;
    sfTexture *t_a;
    sfSprite *s_runner;
    sfVector2f position;
    sfIntRect rect;
    sfVector2f jump;
} runner;

typedef struct cible {
    sfSprite *sprite;
    sfVector2f speed;
    int type;
} cible;

typedef struct map {
    cible *s1;
    cible *s2;
    cible *s3;
    cible *s4;
    sfVector2f m_s1;
    sfVector2f m_s2;
    sfVector2f m_s3;
    sfVector2f m_s4;
    sfVector2f move;
    sfIntRect rect;
    sfTexture *seagull;
    sfTexture *barrel;
    sfTexture *block;
    sfTexture *enemy;
    sfTexture *ship;
    int cmpt_x;
    int cmpt_y;
    sfVector2f speed_fix;
    sfVector2f speed_fast;
    int num;
    int size;
    char *map;
} map;

typedef struct endgame {
    sfText *score;
    sfText *quit;
    sfText *restart;
    sfSprite *s_quit;
    sfSprite *s_restart;
    sfSprite *my_back;
    sfText *result;
    sfTexture *button;
    sfTexture *back;
} endgame;

game_menu *create_title(game_menu *my_menu);
game_menu *color_button(game_menu *my_menu, sfVector2i mouse_position);
game_menu *create_menu(void);
game_menu *destroy_menu(game_menu *my_menu);
void draw_menu(game_menu *my_menu, sfRenderWindow *window);
int play_game(s_pause *my_pause, game *my_game, sounds *my_sounds);
parallax *create_parallax(game *my_game);
void draw_parallax(parallax *my_back, sfRenderWindow *window);
sfSprite *create_object(char *pathname);
sfText *create_score(void);
void draw_score(sfText *my_score, sfRenderWindow *window, int score, \
s_pause *my_pause);
void pause_menu(game *my_game, s_pause *my_pause);
s_pause *create_buttons(s_pause *my_pause, sfVector2f scale);
s_pause *create_texts(s_pause *my_pause, sfVector2f pos_c, sfVector2f pos_r, \
sfVector2f pos_q);
s_pause *color_buttons(s_pause *my_pause, sfVector2i mouse_position, \
int *ptr_pause, game *my_game);
void open_menu(sfRenderWindow *window, int life, int play_music);
s_pause *create_pause(game_menu *my_menu);
s_pause *create_button_p(s_pause *my_pause);
s_pause *change_button(s_pause *my_pause);
s_pause *remove_pause(s_pause *my_pause, int *ptr_pause);
runner *create_user(game *my_game);
sfIntRect create_clock(sfIntRect rect, int offset, int max_value, \
game *my_game);
game *jump(runner *my_pirate, game *my_game);
game *attack(runner *my_pirate, game *my_game, map *my_map);
game *run(runner *my_pirate, game *my_game);
void test_action(runner *my_pirate, game *my_game);
game *create_game(sfRenderWindow *window, sfEvent event, \
s_pause *my_pause);
void update_game(game *my_game);
void check_position(parallax *my_back, sfRenderWindow *window);
choices *create_choices(void);
void choose_lvl_skin(game *my_game, s_pause *my_pause, sounds *my_sounds);
sfIntRect change_rect(sfIntRect rect);
void change_level(game *my_game, choices *my_choices, sfVector2i mouse_pos, \
s_pause *my_pause);
char *get_map(map *my_map);
map *create_map(void);
void draw_map(game *my_game, map *my_map);
sounds *create_sounds(void);
void check_colision(game *my_game, s_pause *my_pause, map *my_map, \
runner *my_pirate);
void game_stop(game *my_game, s_pause *my_pause, int win);
void create_select(choices *my_choices);
void draw_end(game *my_game, endgame *my_end);
endgame *create_text2(s_pause *my_pause, int win, endgame *my_end);
endgame *create_text3(endgame *my_end);
cible *change_sprite(cible *my_cible, sfTexture *texture, \
sfVector2f position, map *my_map);
cible *walk_in_map(map *my_map, char *map, cible *my_cible);
map *refresh_sprite(map *my_map, char *map);
map *create_enemy(map *my_map);
cible *check_sprite(int pos, cible *my_cible, struct map *my_map, \
sfVector2f position);
void destroy_enemy(runner *my_pirate, game *my_game, map *my_map);
void update_play(parallax *my_back, game *my_game, \
s_pause *my_pause, runner *my_pirate);

#endif /* MAIN_RUNNER_H_ */
