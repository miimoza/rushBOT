#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include "context.h"
#include "render.h"

struct GameContext game;

int main(int argc, char *argv[])
{
    if (argc != 2)
        errx(1, "Please enter path for map like: ./toto <path>");
    gameInit(&game, argv[1]);
    render_map(game.map);
    while (game.isPlaying)
    {
        printf("tamerelapute\n");
    }
    return 0;
}
