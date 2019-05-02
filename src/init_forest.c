/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_forest
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void initialisation_sprite_forest_one(window_t *win)
{
    init_sprite(&win->scene[FOREST].sprite[0],
    "ressources/images/forest.png", get_pos_float(0, 0));
    init_sprite(&win->scene[FOREST].sprite[1],
    "ressources/images/tree.png", get_pos_float(30, 245));
    init_sprite(&win->scene[FOREST].sprite[2],
    "ressources/images/tree.png", get_pos_float(55, 10));
    init_sprite(&win->scene[FOREST].sprite[3],
    "ressources/images/tree.png", get_pos_float(125, 95));
    init_sprite(&win->scene[FOREST].sprite[4],
    "ressources/images/tree.png", get_pos_float(545, 3));
    init_sprite(&win->scene[FOREST].sprite[5],
    "ressources/images/tree2.png", get_pos_float(335, 210));
    init_sprite(&win->scene[FOREST].sprite[6],
    "ressources/images/tree2.png", get_pos_float(632, 342));
    init_sprite(&win->scene[FOREST].sprite[7],
    "ressources/images/tree.png", get_pos_float(505, 595));
    init_sprite(&win->scene[FOREST].sprite[8],
    "ressources/images/tree.png", get_pos_float(220, 465));
    init_sprite(&win->scene[FOREST].sprite[9],
    "ressources/images/tree.png", get_pos_float(265, 640));
}

static void initialisation_sprite_forest_two(window_t *win)
{
    init_sprite(&win->scene[FOREST].sprite[10],
    "ressources/images/tree2.png", get_pos_float(25, 775));
    init_sprite(&win->scene[FOREST].sprite[11],
    "ressources/images/tree.png", get_pos_float(485, 810));
    init_sprite(&win->scene[FOREST].sprite[12],
    "ressources/images/tombe.png", get_pos_float(1112, 610));
    init_sprite(&win->scene[FOREST].sprite[13],
    "ressources/images/tree.png", get_pos_float(1625, 45));
    init_sprite(&win->scene[FOREST].sprite[14],
    "ressources/images/tree2.png", get_pos_float(1180, 40));
    init_sprite(&win->scene[FOREST].sprite[15],
    "ressources/images/tree2.png", get_pos_float(1575, 255));
    init_sprite(&win->scene[FOREST].sprite[16],
    "ressources/images/tree.png", get_pos_float(1635, 700));
    initialisation_sprite_forest_one(win);
}

static void depth_sprite_forest(window_t *win)
{
    win->scene[FOREST].sprite[0].depth = -1;
    for (int i = 1; i < win->scene[FOREST].nb_sprite; i++)
        win->scene[FOREST].sprite[i].depth = 1;
}

window_t *init_forest(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 17);
    set_next_buttons(&win->scene[FOREST].button[0], win->rect_buttons,
    order_button[0]);
    init_button(&win->scene[FOREST].button[0], get_pos_float(-200, -200),
    size, win->texture_button);
    set_next_buttons(&win->scene[FOREST].button[1], win->rect_buttons,
    order_button[1]);
    init_button(&win->scene[FOREST].button[1], get_pos_float(-200, -200),
    size, win->texture_button);
    initialisation_sprite_forest_two(win);
    depth_sprite_forest(win);
    win->scene[FOREST].button[0].callback = &quit_pause;
    win->scene[FOREST].button[1].callback = &main_menu;
    return (win);
}