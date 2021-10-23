#ifndef ABC_HW2_CARTOON_H
#define ABC_HW2_CARTOON_H

//------------------------------------------------------------------------------
// cartoon.h - содержит описание мультфильма
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"

//------------------------------------------------------------------------------
// мультфильм
class Cartoon: public Film {
public:
    virtual ~Cartoon(){}
    // Ввод параметров мультфильма
    virtual void In(FILE *f_in);
    // Случайный ввод параметров мультфильма
    virtual void InRnd();
    // Вывод параметров мультфильма
    virtual void Out(FILE *f_out);
private:
    enum cr_type {DRAWN, PUPPET, PLASTICINE};
    cr_type cr_tp;
};

#endif //ABC_HW2_CARTOON_H
