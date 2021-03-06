/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button
*/

#include "../include/rpg.h"
#include "../include/my.h"

int button_is_clicked(button_t button, sfVector2i click_position)
{
    sfVector2f pos_button = sfRectangleShape_getPosition(button.shape);
    sfVector2f size_button = sfRectangleShape_getSize(button.shape);

    if (click_position.x > pos_button.x &&
    click_position.x < size_button.x + pos_button.x) {
        if (click_position.y > pos_button.y &&
        click_position.y < size_button.y + pos_button.y) {
            return (1);
        }
    }
    return (0);
}

int button_is_hovered(button_t button, sfVector2i mouse_position)
{
    sfVector2f pos_button = sfRectangleShape_getPosition(button.shape);
    sfVector2f size_button = sfRectangleShape_getSize(button.shape);

    if (mouse_position.x > pos_button.x &&
    mouse_position.x < size_button.x + pos_button.x) {
        if (mouse_position.y > pos_button.y &&
        mouse_position.y < size_button.y + pos_button.y) {
            return (1);
        }
    }
    return (0);
}

void set_next_buttons(button_t *button, sfIntRect *rect, int type)
{
    button->rect_idle = rect[type];
    button->rect_hovered = get_rect(button->rect_idle.left,
    button->rect_idle.top + 80,
    button->rect_idle.width, button->rect_idle.height);
    button->rect_pressed = get_rect(button->rect_idle.left,
    button->rect_idle.top + 160,
    button->rect_idle.width, button->rect_idle.height);
}

sfIntRect *init_pos_button(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect) * 12);

    if (rect == NULL)
        return (NULL);
    rect[JOUER] = get_rect(3, 0, 259, 76);
    rect[PARAM] = get_rect(3, 240, 259, 76);
    rect[QUITTER] = get_rect(3, 720, 259, 76);
    rect[REPRENDRE] = get_rect(270, 480, 259, 76);
    rect[RETOUR] = get_rect(270, 0, 259, 76);
    rect[NOUVEAU] = get_rect(270, 720, 259, 76);
    rect[SAUVEGARDER] = get_rect(537, 0, 259, 76);
    rect[FLECHE_REVERSE] = get_rect(543, 241, 112, 74);
    rect[CURSEUR] = get_rect(668, 243, 112, 74);
    rect[PAUSE] = get_rect(539, 483, 112, 74);
    rect[TUTORIEL] = get_rect(535, 723, 259, 76);
    rect[FLECHE] = get_rect(666, 484, 112, 74);
    return (rect);
}

int init_button(button_t *but, sfVector2f pos, sfVector2f size, sfTexture *tx)
{
    if (but == NULL || tx == NULL)
        return (84);
    but->shape = sfRectangleShape_create();
    if (but->shape == NULL)
        return (84);
    sfRectangleShape_setPosition(but->shape, pos);
    sfRectangleShape_setSize(but->shape, size);
    sfRectangleShape_setTexture(but->shape, tx, sfTrue);
    sfRectangleShape_setTextureRect(but->shape, but->rect_idle);
    return (0);
}