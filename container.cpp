//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(int s): len{0}, size{s} {
    storage = new Film*[s];
}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
    delete[] storage;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE *f_in) {
    int type = 0;
    len = 0;
    while (fscanf(f_in, "%d", &type) != EOF) {
        if ((storage[len] = Film::StaticIn(f_in, type)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int s) {
    if(s > size) {
        s = size;
    }
    while(len < s) {
        if((storage[len] = Film::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE *f_out) {
    fprintf(f_out, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(f_out, "%d: ", i);
        storage[i]->Out(f_out);
    }
}

// Вычисление среднего значения функции нахождения частного
// от деления года выхода на длину названия для всех фильмов в контейнере
double Container::DivideYearByLengthAverage() {
    double sum = 0.0;
    for(int i = 0; i < len; i++) {
        sum += storage[i]->DivideYearByLength();
    }
    return sum / len;
}

void Container::FilterContainer() {
    double average = DivideYearByLengthAverage();
    int k = 0;
    for (int i = 0; i < len - k;) {
        if (storage[i]->DivideYearByLength() < average) {
            for (int j = i; j < len - k - 1; ++j) {
                storage[j] = storage[j + 1];
            }
            ++k;
        } else {
            ++i;
        }
    }
    len -= k;
}
