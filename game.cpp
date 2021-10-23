//------------------------------------------------------------------------------
// game.cpp - содержит функции обработки игрового фильма
//------------------------------------------------------------------------------

#include "game.h"

//------------------------------------------------------------------------------
// Ввод параметров игрового фильма из файла
void Game::In(FILE *f_in) {
    fscanf(f_in, "%d %s %s", &publication_year, name, director);
}

// Случайный ввод параметров игрового фильма
void Game::InRnd() {
    // Возможный для получения год - от 1896 (год выпуска первого в истории фильма) до 2021 (текущий год)
    publication_year = rand() % 126 + 1896;
    int name_length = rand() % 19 + 1;
    for (int i = 0; i < name_length; ++i) {
        name[i] = 'a' + rand() % 26;
    }
    name[name_length] = '\0';
    int director_length = rand() % 19 + 1;
    for (int i = 0; i < director_length; ++i) {
        director[i] = 'a' + rand() % 26;
    }
    director[name_length] = '\0';
}

//------------------------------------------------------------------------------
// Вывод параметров игрового фильма в файл
void Game::Out(FILE *f_out) {
    fprintf(f_out, "\nIt is Game Film:\n publication year = %d "
                   "\nfilm name = %s \ndirector name = %s \nDivision result = %f\n",
                   publication_year, name, director, DivideYearByLength());
}
