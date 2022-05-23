/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/System/Time.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Music.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define left_ 20
#define right_ 21
#define up_ 22
#define down_ 23

#define walk_ 24
#define stand_ 25

#define writing_ 26
#define ended_ 27

typedef struct bol_s {
    bool htp;
    bool select;
    bool intro;
    bool menu;
    bool pause;
    bool loading;
    bool map;
    bool play;
    bool player;
    bool dialog;
    int load;
    bool boy;
    bool muted;
} bol_t;

typedef struct map_s {
    sfSprite *spr;
    sfSprite *poto_spr;
    sfTexture *text;
    sfTexture *poto_text;
    sfImage *img;
    sfClock *clock;
    sfTime time;
} map_t;

typedef struct pokemon_s {
    sfSprite *spr;
    sfTexture *text;
    int hp;
    int hp_max;
    int dmg;
    int lvl;
} pokemon_t;

typedef struct player_s {
    sfSprite **spr;
    sfTexture **text;
    int i;
    int state;
    int dir;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    pokemon_t pika;
} player_t;

typedef struct cynthia_s {
    sfSprite **spr;
    sfTexture **text;
    int i;
    int dir;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    pokemon_t ronflex;
    bool fight;
    bool discuss;
    bool quest;
    bool heal;
    bool healed;
    int cursor;
} cynthia_t;

typedef struct ht_s {
    int left;
    int top;
    int right;
    int bottom;
} ht_t;

typedef struct inventory_s {
    pokemon_t pok;
    sfText *berry;
    int berries;
    char *berries_str;
} inventory_t;

typedef struct music_s {
    sfMusic *menu;
    sfMusic *htp;
    sfMusic *theme;
    sfMusic *select;
} music_t;

typedef struct menu_s {
    sfSprite *htp_spr;
    sfTexture *htp_text;
    sfSprite *menu_spr;
    sfTexture *menu_text;
    sfSprite *select_spr;
    sfTexture *select_text;
} menu_t;

typedef struct pause_s {
    sfSprite *pause_spr;
    sfTexture *pause_text;
    sfTexture *muted;
} pause_t;

typedef struct dialog_s {
    sfSprite *spr;
    sfTexture *text;
    sfFont *font;
    sfText *txt;
    sfText *cursor;
    char *str;
    int state;
} dialog_t;

typedef struct loading_s {
    sfSprite *spr;
    sfTexture *text;
    sfSprite *load_spr;
    sfTexture *load_text;
} loading_t;

typedef struct rpg_s {
    sfRenderWindow* window;
    sfEvent event;
    bol_t bol;
    map_t map;
    player_t player;
    cynthia_t cynthia;
    ht_t *hit;
    music_t musics;
    menu_t menu;
    pause_t pause;
    dialog_t dialog;
    inventory_t inventory;
    loading_t load;
} rpg_t;

rpg_t create_one(sfVideoMode mode);
void get_spr_dimensions(sfSprite *spr);
int c_two(rpg_t *rpg);
int c_three(rpg_t *rpg);
int c_four(rpg_t *rpg);
int c_five(rpg_t *rpg);
int c_six(rpg_t *rpg);
int c_seven(rpg_t *rpg);
int c_eight(rpg_t *rpg);
bool key_pressed(rpg_t *rpg);
void manage_display(rpg_t *rpg);
void display_select(rpg_t *rpg);
bool inputs_pause(rpg_t *rpg, sfVector2i mouse);
bool inputs_select(rpg_t *rpg, sfVector2i mouse);
bool inputs_htp(rpg_t *rpg, sfVector2i mouse);
bool inputs_menu(rpg_t *rpg, sfVector2i mouse);
int create_hitboxes(rpg_t *rpg);
int destroy(rpg_t *rpg);
void display_player(rpg_t *rpg);
bool inputs_play(rpg_t *rpg);
bool same_color(sfColor color1, sfColor color2);
void player_move(rpg_t *rpg);
int create_cynthia(rpg_t *rpg);
void display_cynthia(rpg_t *rpg);
bool is_in_confilict(sfSprite *obj, sfVector2f pos_obj,
sfSprite *obs, sfVector2f pos_obs);
int create_boy(rpg_t *rpg);
int create_girl(rpg_t *rpg);
void save_game(rpg_t *rpg);
int load_save(rpg_t *rpg);
void mute_musics(rpg_t *rpg, bool mute);
rpg_t set_loading(rpg_t rpg);
void display_play(rpg_t *rpg);
void display_dialog(rpg_t *rpg);
bool talk_cynthia(rpg_t *rpg);
int c_nine(rpg_t *rpg);
void fight(rpg_t *rpg);
bool inputs_dialog(rpg_t *rpg);
void heal_pok(rpg_t *rpg);