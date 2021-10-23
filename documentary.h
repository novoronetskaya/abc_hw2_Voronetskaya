#ifndef ABC_HW2_DOCUMENTARY_H
#define ABC_HW2_DOCUMENTARY_H

//------------------------------------------------------------------------------
// documentary.h - содержит описание документального фильма
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"

//------------------------------------------------------------------------------
// документальный фильм
class Documentary: public Film {
public:
    virtual ~Documentary() {}
    // Ввод параметров документального фильма
    virtual void In(FILE *f_in);
    // Случайный ввод параметров документального фильма
    virtual void InRnd();
    // Вывод параметров документального фильма
    virtual void Out(FILE *f_out);
private:
    int length;
};

#endif //ABC_HW2_DOCUMENTARY_H
