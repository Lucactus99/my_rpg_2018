/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_options
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int init_texts_two(window_t *win, char **text, sfVector2f pos_window)
{
    char *str = NULL;

    if (init_text(&win->scene[OPTIONS].text[3], text[3],
    get_pos_float(pos_window.x, pos_window.y - 230), win->font_berlin) == 84)
        return (84);
    str = my_strcat(my_itc(win->music->volume), "%");
    if (init_text(&win->scene[OPTIONS].text[4], str,
    get_pos_float(pos_window.x + 50, pos_window.y - 150),
    win->font_berlin) == 84)
        return (84);
    if (init_text(&win->scene[OPTIONS].text[5], text[5],
    get_pos_float(925, 130), win->font_berlin) == 84)
        return (84);
    if (init_text(&win->scene[OPTIONS].text[6], text[6],
    get_pos_float(1125, 130), win->font_berlin) == 84)
        return (84);
    return (0);
}

static int init_texts(window_t *win)
{
    sfVector2f size = get_pos_float(500, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;
    char *str = {"OPTIONS\nFPS\nVSYNC\nVolume\n100%\n30\n60\n"};
    char **text = transform_2d(str, '\n');

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = 800;
    if (init_text(&win->scene[OPTIONS].text[0], text[0],
    get_pos_float(pos_window.x + 150, 10), win->font_berlin) == 84)
        return (84);
    if (init_text(&win->scene[OPTIONS].text[1], text[1],
    get_pos_float(pos_window.x, 210), win->font_berlin) == 84)
        return (84);
    if (init_text(&win->scene[OPTIONS].text[2], text[2],
    get_pos_float(pos_window.x, pos_window.y - 430), win->font_berlin) == 84)
        return (84);
    if (init_texts_two(win, text, pos_window) == 84)
        return (84);
    return (0);
}

static int init_buttons(window_t *win)
{
    int order_button[] = {SAUVEGARDER, CURSEUR, CURSEUR, CURSEUR, CURSEUR};
    int pos_x_pos[] = {900, 910, 1115, 1000, win->music->pos_sound.x};
    int pos_y_pos[] = {800, 200, 200, 350, win->music->pos_sound.y};
    int pos_x_size[] = {500, 80, 80, 100, 150};
    int pos_y_size[] = {100, 80, 80, 100, 100};

    for (int i = 0; i < win->scene[OPTIONS].nb_button; i++) {
        set_next_buttons(&win->scene[OPTIONS].button[i],
        win->rect_buttons, order_button[i]);
        if (init_button(&win->scene[OPTIONS].button[i],
        get_pos_float(pos_x_pos[i], pos_y_pos[i]),
        get_pos_float(pos_x_size[i], pos_y_size[i]), win->texture_button) == 84)
            return (84);
    }
    return (0);
}

window_t *init_options(window_t *win)
{
    if (set_struct(win, 5, 7, 1) == 84)
        return (NULL);
    win->music->vol_register = (win->music->volume + VALUE_FIRST) * 1.284;
    if (init_sprite(&win->scene[OPTIONS].sprite[0],
    "ressources/images/menu.png", get_pos_float(0, 0)) == 84)
        return (NULL);
    if (init_texts(win) == 84)
        return (NULL);
    if (init_buttons(win) == 84)
        return (NULL);
    set_fps(win);
    if (set_vsync(win) == 84)
        return (NULL);
    win->scene[OPTIONS].button[0].callback = &main_menu;
    win->scene[OPTIONS].button[1].callback = &change_fps;
    win->scene[OPTIONS].button[2].callback = &change_fps;
    win->scene[OPTIONS].button[3].callback = &change_vsync;
    win->scene[OPTIONS].button[4].callback = NULL;
    return (win);
}