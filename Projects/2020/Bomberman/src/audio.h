#ifndef AUDIO_H
#define AUDIO_H

enum audio {
    MOVE,
    WIN,
    LOSE,
    BOMB,
    EXPLOSION,
    PW_FLAME,
    PW_BOMB,
    IGM,
    BGM
};

void play_audio(enum audio type);

#endif
