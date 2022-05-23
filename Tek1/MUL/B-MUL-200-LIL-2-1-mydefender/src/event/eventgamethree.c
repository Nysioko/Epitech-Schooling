/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** eventgamethree
*/

#include "my_defender.h"

void placetower(bag_t *bag, int i)
{
    if (bag->don.twronedon == 1)
        bag->don.wayn[i] = 1;
    if (bag->don.twrtwodon == 1)
        bag->don.wayn[i] = 2;
    if (bag->don.twrthreedon == 1)
        bag->don.wayn[i] = 3;
    if (bag->don.twrfourdon == 1)
        bag->don.wayn[i] = 4;
    bag->don.twronedon = 0;
    bag->don.twrtwodon = 0;
    bag->don.twrthreedon = 0;
    bag->don.twrfourdon = 0;
    soundplay(bag);
}