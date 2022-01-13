//
// Created by grongo on 12/26/21.
//
#include <stdlib.h>
#include "my_string.h"

typedef union {
    String string;
    double number;
} element_u;

typedef enum {
    STRING,
    FLOAT
} type_t;

typedef struct {
    element_u data;
    type_t type;
} element;

typedef struct {
    String name;
    element *array;
    type_t type;
    size_t used;
    size_t size;
} Column;


void init_column(Column *a , size_t initialSize) {
    a->array = (element *)malloc(initialSize * sizeof(element));
    a->used = 0;
    a->size = initialSize;
}

void push_element(Column *dest, element value) {
    if (dest->used == dest->size) {
        dest->size += 1;
        dest->array = (element *) realloc(dest->array, dest->size * sizeof(char));
    }
    dest->array[dest->used++] = value;
}


void free_column(Column *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void print_element(char *prefix, element e, char *suffix) {

    if (e.type == STRING) {
        printf("%s%s%s", prefix, e.data.string.array, suffix);
    } else
        printf("%s%f%s", prefix, e.data.number, suffix);

}

