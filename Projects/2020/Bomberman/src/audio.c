#include "audio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

static Mix_Chunk *pw_flame; //recoger flame
static Mix_Chunk *put_bomb; //poner bomba
static Mix_Chunk *explosion; //explota la bomba
static Mix_Chunk *move; //movimiento del jugador
static Mix_Chunk *pw_bomb; //recoger BOMB
static Mix_Chunk *win;
static Mix_Chunk *lose;
static Mix_Music *bgm; // para menu 
static Mix_Music *igm; //musica ingame

void init_audio () {
    bgm = Mix_LoadMUS("audio/bgm.mp3");
    pw_flame = Mix_LoadWAV("audio/flame_power.ogg");
    put_bomb= Mix_LoadWAV("audio/p_bomb.ogg");
    explosion = Mix_LoadWAV("audio/explosion.wav");
    move = Mix_LoadWAV("audio/move.ogg");
    pw_bomb = Mix_LoadWAV("audio/bomb_power.ogg");
    igm = Mix_LoadMUS("audio/IGM.wav");
    win = Mix_LoadWAV("audio/win.wav");
    lose = Mix_LoadWAV("audio/lose.wav");
}

void clean_audio() {
    Mix_FreeChunk(pw_flame);
    Mix_FreeChunk(pw_bomb);
    Mix_FreeChunk(explosion);
    Mix_FreeChunk(move);
    Mix_FreeChunk(win);
    Mix_FreeChunk(lose);
    Mix_FreeChunk(put_bomb);
    Mix_FreeMusic(bgm);
    Mix_FreeMusic(igm);
}

void play_audio(enum audio type) {
    switch (type) {
        case MOVE: Mix_PlayChannel(-1,move,0); break;
        case WIN: Mix_PlayChannel(-1,win,0); break;
        case LOSE: Mix_PlayChannel(-1,lose,0); break;
        case BOMB: Mix_PlayChannel(-1,put_bomb,0); break;
        case EXPLOSION: Mix_PlayChannel(-1,explosion,0); break;
        case PW_FLAME: Mix_PlayChannel(-1,pw_flame,0); break;
        case PW_BOMB: Mix_PlayChannel(-1,pw_bomb,0); break;
        case IGM: Mix_PlayMusic(igm,-1); break;
        case BGM: Mix_PlayMusic(bgm,-1); break;
    }
}
