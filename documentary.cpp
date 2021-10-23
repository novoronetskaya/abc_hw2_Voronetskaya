//------------------------------------------------------------------------------
// documentary.cpp - содержит функции обработки документального фильма
//------------------------------------------------------------------------------

#include "documentary.h"

//------------------------------------------------------------------------------
// Ввод параметров документального фильма из файла
void Documentary::In(FILE *f_in) {
    fscanf(f_in, "%d %d %s", &publication_year, &length, name);
}

// Случайный ввод параметров документального фильма
void Documentary::InRnd() {
    // Возможный для получения год - от 1896 (год выпуска первого в истории фильма) до 2021 (текущий год)
    publication_year = rand() % 126 + 1896;
    int name_length = rand() % 19 + 1;
    for (int i = 0; i < name_length; ++i) {
        name[i] = 'a' + rand() % 26;
    }
    name[name_length] = '\0';
    // Возможный для получения год - от 1 до 14400 минут (длительность самого долгого в мире фильма)
    length = rand() % 14400 + 1;
}

//------------------------------------------------------------------------------
// Вывод параметров документального фильма в файл
void Documentary::Out(FILE *f_out) {
    fprintf(f_out, "\nIt is Documentary Film:\n publication year = %d "
                   "\nfilm name = %s \nfilm length =  %d \nDivision result = %f\n",
            publication_year, name, length, DivideYearByLength());
}
