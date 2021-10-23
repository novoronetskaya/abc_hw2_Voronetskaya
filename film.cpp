//------------------------------------------------------------------------------
// film.cpp - содержит процедуры связанные с обработкой обобщенного фильма
// и создания произвольного фильма
//------------------------------------------------------------------------------

#include "game.h"
#include "cartoon.h"
#include "documentary.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного фильма из файла
Film *Film::StaticIn(FILE *f_in, int type = -1) {
    if (type == -1) {
        fscanf(f_in, "%d", &type);
    }
    Film *film = nullptr;
    switch (type) {
        case 1:
            film = new Game;
            break;
        case 2:
            film = new Cartoon;
            break;
        case 3:
            film = new Documentary;
            break;
    }
    film->In(f_in);
    return film;
}

// Случайный ввод обобщенного фильма
Film *Film::StaticInRnd() {
    auto k = rand() % 3 + 1;
    Film *sp = nullptr;
    switch (k) {
        case 1:
            sp = new Game;
            break;
        case 2:
            sp = new Cartoon;
            break;
        case 3:
            sp = new Documentary;
            break;
    }
    sp->InRnd();
    return sp;
}

// Вычисление частного от деления года выхода на длину названия обобщенного фильма
double Film::DivideYearByLength() {
    return (double)(publication_year) / strlen(name);
}

