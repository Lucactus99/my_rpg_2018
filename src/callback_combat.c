/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_combat
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void check_life(window_t *win, int damage)
{
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    win->enemy->health -= damage;
    if (win->enemy->health <= 0) {
        sfSprite_setPosition(win->player->sprite->sprite,
        win->player->last_pos);
        if (win->combat == 3)
            win->page = END;
        else
            win->page = FINAL;
    } else {
        sfText_setString(win->enemy->text->str, my_itc(win->enemy->health));
        win->turn = 1;
    }
}

static void do_attack(window_t *win, int type)
{
    sfIntRect rect;

    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT].sprite[0].sprite);
        if (type == 1)
            rect.top = 8;
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
        sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[2].sprite, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        my_wait(win, 1);
    }
}

void basic_attack(window_t *win)
{
    if (win->turn == 1)
        return;
    my_wait(win, 10);
    sfMusic_play(win->music->basic_attack);
    do_attack(win, 2);
    check_life(win, 20 + (win->player->strength / 10));
}

void special_attack(window_t *win)
{
    char *str = NULL;

    if (win->turn == 1)
        return;
    my_wait(win, 2);
    sfMusic_play(win->music->special_attack);
    do_attack(win, 1);
    win->player->health -= win->player->strength / 10;
    if (win->player->health < win->player->actual_health)
        win->player->actual_health = win->player->health;
    str = my_strcat(my_itc(win->player->actual_health), "/");
    str = my_strcat(str, my_itc(win->player->health));
    sfText_setString(win->scene[COMBAT].text[0].str, str);
    check_life(win, 30 + (win->player->strength / 10));
}