#include <string.h>

typedef struct
{
    char *array;
    size_t used;
    size_t size;
} String;

void init_string(String *a, const char *source, size_t initialSize)
{
    if (source == NULL)
    {
        a->array = malloc(initialSize * sizeof(char));
        a->used = 0;
        a->size = initialSize;
    } else
    {
        a->array = malloc(sizeof(char) * strlen(source));
        strcpy(a->array, source);
        a->used = 1;
        a->size = strlen(source);
    }
}


void append_string(String *dest, char element)
{
    if (dest->used == dest->size)
    {
        dest->size += 1;
        dest->array = realloc(dest->array, dest->size * sizeof(char));
    }
    dest->array[dest->used++] = element;
}

void free_string(String *a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
