/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_rpg.h
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifndef MY_RPG_H_

    #define MY_RPG_H_

    #define PI 3.141592741f

    #define MAX_PARTICLES 10

    #define WIDTH 1920
    #define HEIGHT 1080

    #define GET_BOUNDS(rectangle) \
    sfRectangleShape_getGlobalBounds(rectangle)

    #define DRAW_RECTANGLE(rectangle) \
    sfRenderWindow_drawRectangleShape(var->window, rectangle, NULL)

    #define DRAW_SPRITE(sprite) \
    sfRenderWindow_drawSprite(var->window, sprite, NULL)

    #define CREATE_FROM_FILE(filename) \
    sfTexture_createFromFile(filename, NULL)

    #define BLACKSMITH_DIALOG1 \
    "Take this armor !"

    #define BLACKSMITH_DIALOG2 \
    "Attack enemies who\nare higher up !"

    #define PRICILLA_DIALOG1 \
    "Our village need you !\nTalk to the blacksmith !"

    #define PRICILLA_DIALOG2 \
    "Attack enemies who\nare higher up !"

    #define BOB_DIALOG1 \
    "Talk to me later !"

    #define BOB_DIALOG2 \
    "Now you need to defeat the boss\nGo at the bottom of the map !"

typedef struct character {
    bool attack;
    float second;
    sfClock *walk;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *clothes;
    sfTime times;
} char_t ;

typedef struct sound_s {
    sfMusic *theme;
} sound_t ;

typedef struct particle_s {
    float life;
    float oscillation;
    float rotation;
    float rotationSpeed;
    float size;
    float speed;
    float x;
    float y;
    sfVector2f direction;
} particle_t;

typedef struct dialog_s {
    sfFont *font;
    sfText *text;
    sfText *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
} dialog_t;

typedef struct var {
    bool has_armor;
    bool switch_side;
    char_t *forge;
    char_t *girl;
    char_t *mc;
    char_t *orc;
    char_t *pnj;
    char_t *skel;
    particle_t particles[MAX_PARTICLES];
    sfFloatRect *collider_bounds;
    sfRectangleShape **collider;
    sfRectangleShape *hitbox;
    sfRectangleShape *rect;
    sfRenderWindow *window;
    sfSprite **foreground;
    sfSprite *background_sprite;
    sfTexture *armor;
    sfVector2f orc_pos;
    sfVector2f skel_pos;
    sfView *view;
    size_t frame_count;
    sound_t *sound;
    dialog_t *dialog;
    bool has_talk_to_blacksmith;
    bool is_talking_to_blacksmith;
    bool has_kill_all_mobs;
    int direction;
} var_t;

bool check_intersects(sfFloatRect p_bounds, var_t *var);
bool load_position_map(var_t *var, char *line);
bool load_position_player(var_t *var, char *line);
bool load_quest(var_t *var, char *line);
char *int_to_str(int nb, size_t *n);
int get_digits(int nb);
sfRenderWindow *create_window(void);
void attack_back(var_t *var);
void attack_front(var_t *var);
void attack_left(var_t *var);
void attack_move(var_t *var);
void attack_right(var_t *var);
void back_move(var_t *var);
void blacksmith_dialog(var_t *var);
void bob_dialog(var_t *var);
void check_ennemies(var_t *var);
void check_event(var_t *var, sfEvent event);
void check_move(var_t *var, sfEvent event);
void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds);
void create_barrer_collider(var_t *var);
void create_collider(var_t *var);
void create_dialog_box(var_t *var);
void create_foreground(var_t *var);
void create_house_collider(var_t *var);
void create_north_ouest_position(var_t *var);
void create_north_ouest_size(var_t *var);
void create_png_collider(var_t *var);
void create_sud_collider(var_t *var);
void create_tree_collider(var_t *var);
void create_water_collider(var_t *var);
void create_west_collider(var_t *var);
void display_orc(var_t *var);
void display_orc2(var_t *var);
void display_skel(var_t *var);
void display_skel2(var_t *var);
void forge_move(var_t *var);
void front_move(var_t *var);
void game_engine(var_t *var, sfSprite *particle_sprite);
void generate_particle(var_t *var);
void girl_move(var_t *var);
void init_char(var_t *var);
void init_ennemies(var_t *var);
void init_game(var_t *var);
void init_player(var_t *var);
void init_rpg(var_t *var);
void init_struct(var_t *var);
void left_move(var_t *var);
void load_game(const char *file_name, var_t *var);
void move_particle(var_t *var, sfSprite *particle_sprite);
void pnj_move(var_t *var);
void priscilla_dialog(var_t *var);
void right_move(var_t *var);
void save_game(const char *file_name, var_t *var);
void save_position_map(var_t *var, FILE *file);
void save_position_player(var_t *var, FILE *file);
void save_quest(var_t *var, FILE *file);
void set_foreground_position(var_t *var);
void show_blacksmith_dialog(var_t *var);
void show_bob_dialog(var_t *var);
void show_priscilla_dialog(var_t *var);
void zoom_in(var_t *var, bool *has_zoom);
void zoom_out(var_t *var, bool *has_zoom);

#endif /* MY_RPG_H_ */
