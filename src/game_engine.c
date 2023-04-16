/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void check_quest(var_t *var)
{
    if (var->quest_progress == ENEMIES)
        check_enemies(var);
    if (var->quest_progress == BOSS)
        DRAW_SPRITE(var->foreground[9]);
}

void load_game_and_engine(var_t *var, sfEvent event)
{
    load_game("save.txt", var);
    game_engine(var, event);
}

void game_engine2(var_t *var)
{
    sfRenderWindow_clear(var->window, sfBlack);
    sfRenderWindow_setView(var->window, var->view);
    DRAW_SPRITE(var->background_sprite);
    if (PLAYER->attack)
        attack_move(var);
    blacksmith_move(var);
    girl_move(var);
    pnj_move(var);
    check_quest(var);
    DRAW_SPRITE(PLAYER->sprite);
    for (sfUint32 i = 0; i < 9; i++)
        DRAW_SPRITE(var->foreground[i]);
    var->frame_count++;
    move_leaves(var);
    move_particle_pnj(var);
    dialog(var);
    display_ui(var);
    display_life(var);
    sfRenderWindow_display(var->window);
}

void game_engine(var_t *var, sfEvent event)
{
    while (sfRenderWindow_isOpen(var->window)) {
        if (sfRenderWindow_pollEvent(var->window, &event))
            check_event(var, event);
        game_engine2(var);
    }
}
