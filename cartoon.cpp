//------------------------------------------------------------------------------
// cartoon.cpp - содержит функции обработки мультфильма
//------------------------------------------------------------------------------

#include "cartoon.h"

//------------------------------------------------------------------------------
// Ввод параметров мультфильма из файла
void Cartoon::In(FILE *f_in) {
    int tp;
    fscanf(f_in, "%d %d %s", &publication_year, &tp, name);
    switch (tp) {
        case 1:
            cr_tp = Cartoon::DRAWN;
            break;
        case 2:
            cr_tp = Cartoon::PUPPET;
            break;
        case 3:
            cr_tp = Cartoon::PLASTICINE;
            break;
        default:
            return;
    }
}

// Случайный ввод параметров мультфильма
void Cartoon::InRnd() {
    // Возможный для получения год - от 1896 (год выпуска первого в истории фильма) до 2021 (текущий год)
    publication_year = rand() % 126 + 1896;
    int name_length = rand() % 19 + 1;
    for (int i = 0; i < name_length; ++i) {
        name[i] = 'a' + rand() % 26;
    }
    name[name_length] = '\0';
    int tp = rand() % 3 + 1;
    switch(tp) {
        case 1:
            cr_tp = Cartoon::DRAWN;
            break;
        case 2:
            cr_tp = Cartoon::PUPPET;
            break;
        case 3:
            cr_tp = Cartoon::PLASTICINE;
            break;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров мультфильма в файл
void Cartoon::Out(FILE *f_out) {
    fprintf(f_out, "\nIt is Cartoon Film:\n publication year = %d "
                   "\nfilm name = %s \ntype = ",
            publication_year, name);
    switch(cr_tp) {
        case Cartoon::DRAWN:
            fprintf(f_out, "drawn");
            break;
        case Cartoon::PUPPET:
            fprintf(f_out, "puppet");
            break;
        case Cartoon::PLASTICINE:
            fprintf(f_out, "plasticine");
            break;
    }
    fprintf(f_out,"\nDivision result = %f\n", DivideYearByLength());
}
