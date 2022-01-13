#ifndef TASK2_TASK2B_H
#define TASK2_TASK2B_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_column.h"


#include <string.h>

typedef struct
{
    Column *array;
    size_t used_cols;
    size_t col_count;
} DataTable_t;

DataTable_t *initDT(const char *source, size_t initialSize)
{
    DataTable_t *a;
    a->array = malloc(initialSize * sizeof(char));
    a->used_cols = 0;
    a->col_count = initialSize;

    return a;
}


void deinitDT(DataTable_t *a)
{
    free(a->array);
    a->array = NULL;
    a->used_cols = a->col_count = 0;
}

DataTable_t *init_DT();

void loadDT(DataTable_t *some_table, char *file_name);

void exportDT(const DataTable_t *some_table, char *file_name);

void display_header(DataTable_t *some_table);

void deinitDT(DataTable_t *some_table);

void showDT(DataTable_t *some_table);

DataTable_t *projectDT(DataTable_t *some_table, int m, int n, int x, int y);

void mutateDT(DataTable_t *some_table, int col, void (*some_function)(double *num));

#endif
