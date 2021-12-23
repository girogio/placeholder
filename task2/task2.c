#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int cols;
} DataTable_t;

void display_header(DataTable_t *some_table);

void deinitDT(DataTable_t *some_table);

void showDT(DataTable_t *some_table);

DataTable_t *init_DT(Field_t fields[MAXCOLS], Column cols[MAXCOLS]);

int main() {

//    FILE *stream = fopen("test.csv", "r");
//    char current_char = '\0';
//    while (current_char != EOF) {
//        current_char = (char) fgetc(stream);
//        if (current_char != EOF)
//            if (current_char == ',') {
//                putchar('|');
//            } else if (current_char == '\\') {
//                putchar(fgetc(stream));
//            } else {
//                putchar(current_char);
//            }
//    }

    Field_t fields[] = {
            {"Label0", 'F'},
            {"Label1", 'F'},
            {"Label2", 'F'},
            {"Label3", 'S'},
            {"Label4", 'S'},
            {"Label5", 'S'},
    };

    Column cols[MAXCOLS] = {
            {.number = {1.3, 2.2, 3.4, 4.6, 5.8, 4.6}},
            {.number = {1.3, 2.2, 3.4, 4.6, 5.8, 4.6}},
            {.number = {1.3, 2.2, 3.4, 4.6, 5.8, 4.6}},
            {.string = {"lmao", "easy", "p,easy", "anothaone", "abbb", "a", "A"}},
            {.string = {"lmao", "easy", "peasy", "aaaaaaanothaone", "abbb", "a"}},
            {.string = {"asodma", "aaaa", "peasy", "anothaone", "abbb", "a"}}
    };


    DataTable_t *mytable = init_DT(fields, cols);

    showDT(mytable);

    deinitDT(mytable);

}

DataTable_t *init_DT(Field_t user_fields[MAXCOLS], Column cols[MAXCOLS]) {

    // init pointer
    DataTable_t *myTable = (DataTable_t *) calloc(1, sizeof(DataTable_t));

    // assign all labels
    for (int i = 0; i < MAXCOLS; i++) {
        myTable->fields[i] = user_fields[i];
        myTable->columns[i] = cols[i];
    }

    myTable->cols = sizeof(myTable->fields) / sizeof(myTable->fields[0]);


    return myTable;
}

void deinitDT(DataTable_t *some_table) {
    free(some_table);
}

void display_header(DataTable_t *some_table) {
    for (int i = 0; i < MAXCOLS; i++) {
        printf("%10s\t", some_table->fields[i].name);
    }

    printf("\n");

    for (int i = 0; i < some_table->cols; i++) {
        for (int j = 0; j < 12; j++) {
            printf("-");
        }
    }

    printf("\n");

}

void showDT(DataTable_t *some_table) {

    display_header(some_table);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            switch (some_table->fields[j].type) {

                case 'F':
                    if (some_table->columns[j].number[i] != 0)
                        printf("%10.4f\t", some_table->columns[j].number[i]);
                    else
                        printf("%*s\t", 10, "empty");
                    break;

                case 'S':
                    if (strlen(some_table->columns[j].string[i]) != 0)
                        printf("%10.10s\t", some_table->columns[j].string[i]);
                    else
                        printf("%*s\t", 10, "empty");
                    break;

            }

        }

        printf("\n");
    };

    for (int i = 0; i < MAXCOLS; ++i) {
        printf("%10s\t", "...");
    }
}






