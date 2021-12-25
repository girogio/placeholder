#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXROWS 1000
#define MAXCOLS 6
#define MAXSTRING 64

typedef enum types {
    STRING,
    FLOAT
} Type_t;

typedef union {
    char string[MAXROWS][MAXSTRING];
    double number[MAXROWS];
} Column;

typedef struct {
    char name[MAXSTRING];
    char type;
    int actual_rows;
} Field_t;

typedef struct {
    Field_t fields[MAXCOLS];
    Column columns[MAXCOLS];
} DataTable_t;

DataTable_t *init_DT(Field_t fields[MAXCOLS], Column cols[MAXCOLS]);

void display_header(DataTable_t *some_table);

void deinitDT(DataTable_t *some_table);

void showDT(DataTable_t *some_table);

DataTable_t *projectDT(DataTable_t *some_table, int m, int n, int x, int y);

void mutateDT(DataTable_t *some_table,  int col, void (*some_function)(double *num));