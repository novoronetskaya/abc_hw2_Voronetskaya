#ifndef ABC_HW2_FILM_H
#define ABC_HW2_FILM_H

//------------------------------------------------------------------------------
// film.h - содержит описание обобщающего фильма
//------------------------------------------------------------------------------

#include <stdio.h>

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся типы фильмов
class Film {
public:
    virtual ~Film() {};

    // Ввод обобщенного фильма
    static Film *StaticIn(FILE *f_in, int type);

    // Ввод обобщенного фильма
    virtual void In(FILE *f_in) = 0;

    // Случайный ввод обобщенного фильма
    static Film *StaticInRnd();

    // Виртуальный метод ввода случайной фигуры
    virtual void InRnd() = 0;

    // Вывод обобщенного фильма
    virtual void Out(FILE *f_out) = 0;

    // Вычисление частного от деления года выхода на длину названия обобщённого фильма
    double DivideYearByLength();

protected:
    int publication_year;
    enum key {GAME, CARTOON, DOCUMENTARY};
    key k;
    char name[20] = {0};
};

#endif //ABC_HW2_FILM_H
