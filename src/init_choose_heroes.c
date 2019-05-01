/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_choose_heroes
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_texts(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window = {
        (size_window.x - size.x) / 2,
        (size_window.y - size.y) / 8};
    char *name[] = {
        "Choisissez votre personnage", "Hex-the-Time-Witch", "Vie: ",
        my_itc(70), "Force: ", my_itc(70), "Description"};
    int pos_x[] = {
        pos_window.x + 40, pos_window.x / 2, (pos_window.x - 100) / 2,
        (pos_window.x + 250) / 2, (pos_window.x - 200) / 2,
        (pos_window.x + 250) / 2, (pos_window.x - 200) / 2};
    int pos_y[] = {
        10, 100, (size_window.y - 450), (size_window.y - 450),
        (size_window.y - 350), (size_window.y - 350), (size_window.y - 250)};

    for (int i = 0; i < win->scene[HEROES].nb_text; i++) {
        init_text(&win->scene[HEROES].text[i], name[i],
        get_pos_float(pos_x[i], pos_y[i]));
    }
}

static void init_buttons(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 8;
    set_next_buttons(&win->scene[HEROES].button[0], win->rect_buttons, FLECHE);
    init_button(&win->scene[HEROES].button[0], get_pos_float(pos_window.x + 40,
    (size_window.y / 2)), get_pos_float(size.x / 2, size.y),
    win->texture_button);
    set_next_buttons(&win->scene[HEROES].button[1], win->rect_buttons, FLECHE_REVERSE);
    init_button(&win->scene[HEROES].button[1], get_pos_float(pos_window.x - 200,
    (size_window.y / 2)), get_pos_float(size.x / 2, size.y),
    win->texture_button);
    pos_window.x = (size_window.x - size.x - 10);
    pos_window.y = (size_window.y - (size.y + 50) * 2);
    set_next_buttons(&win->scene[HEROES].button[2], win->rect_buttons, JOUER);
    init_button(&win->scene[HEROES].button[2], pos_window, size,
    win->texture_button);
    pos_window.y += size.y + 10;
    set_next_buttons(&win->scene[HEROES].button[3], win->rect_buttons,
    QUITTER);
    init_button(&win->scene[HEROES].button[3], pos_window, size,
    win->texture_button);
}

window_t *init_choose_heroes(window_t *win)
{
    set_struct(win, 4, 7, 2);
    init_texts(win);
    init_buttons(win);
    init_sprite(&win->scene[HEROES].sprite[0],
    "ressources/images/sprites/Hex-the-Time-Witch.png",
    get_pos_float(100, 100));
    win->scene[HEROES].sprite[0].rect.top = 100;
    win->scene[HEROES].sprite[0].rect.left = 0;
    win->scene[HEROES].sprite[0].rect.width = 50;
    win->scene[HEROES].sprite[0].rect.height = 50;
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite,
    get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].rect);
    init_sprite(&win->scene[HEROES].sprite[1], "ressources/menu.png", get_pos_float(0, 0));
    win->scene[HEROES].sprite[1].depth = -1;
    win->scene[HEROES].button[0].callback = &choose_hero;
    win->scene[HEROES].button[1].callback = &choose_hero_reverse;
    win->scene[HEROES].button[2].callback = &play_game;
    win->scene[HEROES].button[3].callback = &main_menu;
    win->player->hero = 0;
    choose_hex(win);
    return (win);
}