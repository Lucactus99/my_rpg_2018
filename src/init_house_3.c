/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_house_3
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void initialisation_house_three_depth_sprite(window_t *win)
{
    init_sprite(&win->scene[HOUSE3].sprite[1],
    "ressources/images/horloge.png", get_pos_float(638, 412));
    init_sprite(&win->scene[HOUSE3].sprite[2],
    "ressources/images/mirror.png", get_pos_float(1083, 513));
    init_sprite(&win->scene[HOUSE3].sprite[3],
    "ressources/images/table_blanche.png",
    get_pos_float(798, 502));
    init_sprite(&win->scene[HOUSE3].sprite[4],
    "ressources/images/bout_chaise.png",
    get_pos_float(735, 505));
    init_sprite(&win->scene[HOUSE3].sprite[5],
    "ressources/images/bout_chaise.png", get_pos_float(863, 505));
    sfSprite_setPosition(win->scene[HOUSE3].sprite[0].sprite,
    get_pos_float(670, 300));
    win->scene[HOUSE3].sprite[0].depth = -1;
    for (int i = 1; i < win->scene[HOUSE3].nb_sprite; i++)
        win->scene[HOUSE3].sprite[i].depth = 1;
}

window_t *init_house_3(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 6);
    set_next_buttons(&win->scene[HOUSE3].button[0], win->rect_buttons,
    order_button[0]);
    init_button(&win->scene[HOUSE3].button[0], get_pos_float(-200, -200),
    size, win->texture_button);
    set_next_buttons(&win->scene[HOUSE3].button[1], win->rect_buttons,
    order_button[1]);
    init_button(&win->scene[HOUSE3].button[1], get_pos_float(-200, -200),
    size, win->texture_button);
    init_sprite(&win->scene[HOUSE3].sprite[0], "ressources/images/house_3.png",
    get_pos_float(0, 0));
    initialisation_house_three_depth_sprite(win);
    win->scene[HOUSE3].button[0].callback = &quit_pause;
    win->scene[HOUSE3].button[1].callback = &main_menu;
    return (win);
}