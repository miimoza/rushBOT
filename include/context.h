#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "map.h"

enum event
{
    LEFT = 0,
    RIGHT,
    FORWARD,
    BACK,
    NOTHING,
    QUIT
};

struct vector2
{
    float x;
    float y;
};

struct hitbox
{
    struct vector2 *v1;
    struct vector2 *v2;
    struct vector2 *v3;
    struct vector2 *v4;
};

struct tank
{
    struct vector2 *position;
    struct vector2 *direction;
    int health;
    float speed;
    int is_shoting;
    int since_i_shot;
    enum event event;
    struct hitbox *hbox;
    int t_id;
};

enum bulletType
{
    NORMAL = 0,
    HEAVY,
    LIGHT,
    ENORMOUS
};

struct bullet
{
    struct vector2 *position;
    struct vector2 *direction;
    int damage;
    float speed;
    enum bulletType type;
    int nb_rebounds;
    int to_destroy;
    int t_id;
};

struct GameContext
{
    struct map *map;
    struct tank **enemies;
    int nb_enemies;
    struct tank *player1;
    struct tank *player2;
    int isPlaying;
    struct bullet **bullets;
    int nb_bullets;
    int winner;
};

void gameInit(struct GameContext *game, char *arg);
void free_game(struct GameContext *game);
int menu(SDL_Renderer *renderer);
void get_input(struct GameContext *game);



#endif /* !CONTEXT_H */
