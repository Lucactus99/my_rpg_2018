/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** display str
*/

#include <unistd.h>
#include "../../../include/my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}