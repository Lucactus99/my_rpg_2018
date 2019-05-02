/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_text_ok(window_t *win)
{
    char *str = win->player->name;

    str = my_strcat(str, "\n");
    str = my_strcat(str, "Vie: ");
    str = my_strcat(str, my_itc(win->player->actual_health));
    str = my_strcat(str, "/");
    str = my_strcat(str, my_itc(win->player->health));
    str = my_strcat(str, "\n");
    str = my_strcat(str, "Puissance: ");
    str = my_strcat(str, my_itc(win->player->strength));
    str = my_strcat(str, "\n");
    sfText_setString(win->inv->text->str, str);
}

static int set_text_objects(window_t *win, sfVector2f move_pos, int i)
{
    int ok = 0;
    char *str = NULL;

    if (move_pos.y >= win->inv->items[i].pos.y - 10 &&
    move_pos.y < win->inv->items[i].pos.y + 80) {
        ok = 1;
        if (win->inv->items[i].name != NULL) {
            str = my_strcat(win->inv->items[i].name, "\n");
            if (my_strcmp(win->inv->items[i].name, "Dague") == 0)
                str = my_strcat(str, "Puissance + 20");
            if (my_strcmp(win->inv->items[i].name, "Armure") == 0)
                str = my_strcat(str, "Vie + 20");
            sfText_setString(win->inv->text->str, str);
        } else
            sfText_setString(win->inv->text->str, "\n");
    }
    return (ok);
}

void set_text_inv(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f move_pos = get_pos_float(click_pos.x, click_pos.y);
    int ok = 0;

    for (int i = 0; i < 15; i++) {
        if (move_pos.x >= win->inv->items[i].pos.x - 10 &&
        move_pos.x < win->inv->items[i].pos.x + 80) {
            ok = set_text_objects(win, move_pos, i);
        }
    }
    if (ok == 0)
        set_text_ok(win);
}