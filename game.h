#ifndef ABC_HW2_GAME_H
#define ABC_HW2_GAME_H

//------------------------------------------------------------------------------
// game.h - содержит описание игрового фильма
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"

//------------------------------------------------------------------------------
// игровой фильм
class Game: public Film {
public:
    virtual ~Game() {}
    // Ввод параметров игрового фильма
    virtual void In(FILE *f_in);
    // Случайный ввод параметров игрового фильма
    virtual void InRnd();
    // Вывод параметров игрового фильма
    virtual void Out(FILE *f_out);
private:
    char director[20];
};

#endif //ABC_HW2_GAME_H
