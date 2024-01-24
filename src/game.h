#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef struct {
    int hp;
    int max_hp;
    int mp;
    int max_mp;
    // inventory
    // room/dungeon/enemy
} GAMESTATE;

void game_loop();

#endif

