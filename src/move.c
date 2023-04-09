/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** move.c
*/

#include "my_rpg.h"

bool check_intersects(sfFloatRect p_bounds, var_t *var)
{
    for (unsigned int i = 0; i < 65; i++) {
        if (sfFloatRect_intersects(&p_bounds, &var->collider_bounds[i], NULL))
            return true;
    }
    return false;
}

void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds)
{
    if (event.key.code == sfKeyUp) {
        p_bounds.top -= 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){0.0f, -10.0f});
        sfSprite_move(var->mc->sprite, (sfVector2f){0.0f, -10.0f});
        sfRectangleShape_move(var->hitbox, (sfVector2f){0.0f, -10.0f});
        down_move(var);
    }
    if (event.key.code == sfKeyDown) {
        p_bounds.height += 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){0.0f, 10.0f});
        sfSprite_move(var->mc->sprite, (sfVector2f){0.0f, 10.0f});
        sfRectangleShape_move(var->hitbox, (sfVector2f){0.0f, 10.0f});
        up_move(var);
    }
}

void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds)
{
    if (event.key.code == sfKeyLeft) {
        p_bounds.left -= 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){-10.0f, 0.0f});
        sfSprite_move(var->mc->sprite, (sfVector2f){-10.0f, 0.0f});
        sfRectangleShape_move(var->hitbox, (sfVector2f){-10.0f, 0.0f});
        left_move(var);
    }
    if (event.key.code == sfKeyRight) {
        p_bounds.width += 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){10.0f, 0.0f});
        sfSprite_move(var->mc->sprite, (sfVector2f){10.0f, 0.0f});
        sfRectangleShape_move(var->hitbox, (sfVector2f){10.0f, 0.0f});
        right_move(var);
    }
    check_move2(var, event, p_bounds);
}

void check_move(var_t *var, sfEvent event)
{
    sfFloatRect p_bounds = sfSprite_getGlobalBounds(var->mc->sprite);
    sfVector2f size = {0.0f, 0.0f};

    float tmp = p_bounds.height;
    p_bounds.height = p_bounds.height / 5.0f;
    p_bounds.top += tmp - p_bounds.height;
    p_bounds.width = 25.0f;
    p_bounds.left += 15.0f;
    size = (sfVector2f){p_bounds.width, p_bounds.height};
    sfRectangleShape_setSize(var->hitbox, size);
    check_move1(var, event, p_bounds);
}
