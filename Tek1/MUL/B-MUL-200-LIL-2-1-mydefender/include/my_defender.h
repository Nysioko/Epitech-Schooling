/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** my_defender
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

struct sprite_s{
    sfSprite *bcg;
    sfSprite *bcghelp;
    sfSprite *map;
    sfSprite *play;
    sfSprite *back;
    sfSprite *next;
    sfSprite *ctrl;
    sfSprite *exit;
    sfSprite *menu;
    sfSprite *re;
    sfSprite *ng;
    sfSprite **sqg;
    sfSprite *sqgc;
    sfSprite *sqgx;
    sfSprite *sqgo;
    sfSprite *twronesqgo;
    sfSprite *towerchose;
    sfSprite *coin;
    sfSprite ***twr;
    sfSprite ***enemy;
    sfSprite **castle;
    sfSprite *potion;
};
typedef struct sprite_s sprite_t;

struct texture_s{
    sfTexture *bcg;
    sfTexture *bcghelp;
    sfTexture *map;
    sfTexture *play;
    sfTexture *back;
    sfTexture *next;
    sfTexture *ctrl;
    sfTexture *exit;
    sfTexture *ng;
    sfTexture *menu;
    sfTexture *re;
    sfTexture *sqg;
    sfTexture *sqgc;
    sfTexture *sqgx;
    sfTexture *sqgo;
    sfTexture *sqgsable;
    sfTexture *towerchose;
    sfTexture **twr;
    sfTexture **enemy;
    sfTexture *coin;
    sfTexture **castle;
    sfTexture *potion;
};
typedef struct texture_s texture_t;

struct vectorgame_s{
    sfVector2f *ptw;
    sfVector2f scalemap;
};
typedef struct vectorgame_s vectorgame_t;

struct vector_s{
    vectorgame_t vectorgame;
    sfVector2f scalebcg;
    sfVector2f scalebtn;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfVector2f **posenemy;
    sfVector2f helptext;
    sfVector2f mousef;
    sfVector2i mouse;
    sfIntRect potion;
};
typedef struct vector_s vector_t;

struct text_s{
    sfText *money;
    sfText *step;
    sfFont *font;
};
typedef struct text_s text_t;

struct tower_s{
    int *aim;
    int *rotate;
};
typedef struct tower_s tower_t;

struct enemy_s{
    int **pv;
    int **death;
    int **posenemy;
    int step;
    int pvcastle;
};
typedef struct enemy_s enemy_t;

struct myclock_s{
    sfClock *wait;
    sfClock *gain;
    sfClock *apt;
    sfClock *mvmt;
    sfClock *aim;
    sfClock *bank;
    sfClock *gainbank;
    sfClock *castle;
    sfClock *potion;
};
typedef struct myclock_s myclock_t;

struct map_s{
    char ***map;
};
typedef struct map_s map_t;

struct sound_s{
    sfMusic *met;
    sfMusic *pop;
    sfMusic *start;
    int meti;
    int popi;
    int starti;
};
typedef struct sound_s sound_t;

struct drawnot_s{
    int twronedon;
    int twrtwodon;
    int twrthreedon;
    int twrfourdon;
    int *wayn;
};
typedef struct drawnot_s drawnot_t;

struct bag_s{
    sprite_t sprite;
    texture_t texture;
    map_t map;
    sfEvent event;
    myclock_t clock;
    vector_t vector;
    text_t text;
    drawnot_t don;
    sound_t sound;
    enemy_t enemy;
    tower_t tower;
    int menu;
    int money;
};
typedef struct bag_s bag_t;

void texturedestroy(bag_t *bag);
void spritedestroy(bag_t *bag);
void textdestroy(bag_t *bag);
int initexture(bag_t *bag);
int initsprite(bag_t *bag);
int load_var(bag_t *bag);
int load_vargame(bag_t *bag);
void textmoney(sfRenderWindow* window, bag_t *bag);
void menustart(sfRenderWindow* window, bag_t *bag);
void menuend(sfRenderWindow* window, bag_t *bag, int i);
void menuhelp(sfRenderWindow* window, bag_t *bag);
void menupause(sfRenderWindow* window, bag_t *bag);
void textend(sfRenderWindow* window, bag_t *bag, int i);
void drawmenustart(sfRenderWindow* window, bag_t *bag);
void drawmenuhelp(sfRenderWindow* window, bag_t *bag);
void drawmenupause(sfRenderWindow* window, bag_t *bag);
void drawgame(sfRenderWindow* window, bag_t *bag);
void playgame(sfRenderWindow* window, bag_t *bag);
void eventstart(sfRenderWindow* window, bag_t *bag);
void eventpause(sfRenderWindow* window, bag_t *bag);
void eventhelp(sfRenderWindow* window, bag_t *bag);
sfFloatRect get_spritepos(bag_t *bag, sfSprite *sprite);
int towerone(sfRenderWindow* window, sfVector2i mouse, bag_t *bag);
int towertwo(sfRenderWindow* window, sfVector2i mouse, bag_t *bag);
int towerthree(sfRenderWindow* window, sfVector2i mouse, bag_t *bag);
int towerfour(sfRenderWindow* window, sfVector2i mouse, bag_t *bag);
int eventgameone(sfRenderWindow* window, bag_t *bag);
void sprite_cursor(bag_t *bag, sfRenderWindow *window);
char *my_revstr(char *str);
char *int_to_str(int x, char *str);
void placetower(bag_t *bag, int i);
void soundplay(bag_t *bag);
void soundcreate(bag_t *bag);
void soundestroy(bag_t *bag);
void setextsprite(bag_t *bag);
void enemy(sfRenderWindow* window, bag_t *bag);
void load_ennemy(bag_t *bag);
void stepone(sfRenderWindow* window, bag_t *bag);
void steptwo(sfRenderWindow* window, bag_t *bag);
void stepthree(sfRenderWindow* window, bag_t *bag);
void stepfour(sfRenderWindow* window, bag_t *bag);
int verif_step(bag_t *bag, int i);
void freecage_game(bag_t *bag);
void init1(bag_t *bag);
char *my_strcat(char *dest, char *src);
void textstep(sfRenderWindow* window, bag_t *bag);
int my_strlen(char const *str);
void rotation(bag_t *bag, int i, int j);
void initcastle(bag_t *bag);
int initexture_three(bag_t *bag);
void initexture_three2(bag_t *bag);
void initexture_two(bag_t *bag);
int initsprite_twobelike(bag_t *bag);
int initexturethree(bag_t *bag);
void tower_shot(bag_t *bag);
void bank(bag_t *bag);
void tower_one_shot_one(bag_t *bag, int twr, int j);
void tower_two_shot_one(bag_t *bag, int twr, int j);
void tower_three_shot_one(bag_t *bag, int twr, int j);