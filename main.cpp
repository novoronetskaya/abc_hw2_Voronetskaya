//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "container.h"

void errMessage1() {
    printf("Incorrect command line!\n  Waited:\n     command -f infile outfile01 outfile02\n");
    printf("  Or:\n     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n  Waited:\n     command -f infile outfile01 outfile02\n");
    printf("  Or:\n     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    // clock_t start = clock();

    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    Container c{1000};

    if (!strcmp(argv[1], "-f")) {
        FILE *f_in = fopen(argv[2], "r");
        c.In(f_in);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 1000)) {
            printf("Incorrect number of films = %d. Set 0 < number <= 1000\n", size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand((unsigned int) (time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *f_out_1 = fopen(argv[3], "w");
    fprintf(f_out_1, "Filled container:\n");
    c.Out(f_out_1);

    // The 2nd part of task
    FILE *f_out_2 = fopen(argv[4], "w");
    fprintf(f_out_2, "Division result average = %f", c.DivideYearByLengthAverage());
    fclose(f_out_2);

    c.FilterContainer();

    // Вывод содержимого отфильтрованного контейнера в файл
    fprintf(f_out_1, "Filtered container:\n");
    c.Out(f_out_1);
    fclose(f_out_1);

    printf("Stop\n");
    // printf("Total time: %f s\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
