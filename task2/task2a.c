#include "task2a.h"




void exportDT(const DataTable_t *some_table, char *file_name)
{

    FILE *file = fopen(file_name, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int max_row_count = 0;
    for (int i = 0; i < sizeof(some_table->fields) / sizeof(some_table->fields[0]); i++)
    {
        if (some_table->fields[i].actual_rows > max_row_count)
            max_row_count = some_table->fields[i].actual_rows;
    }

    for (int i = 0; i < max_row_count; i++)
    {
        for (int j = 0; j < sizeof(some_table->fields) / sizeof(some_table->fields[0]); j++)
        {
            if (some_table->fields[j].type == STRING)
            {
                for (int k = 0; k < strlen(some_table->columns[j].string[i]); k++)
                {
                    if (some_table->columns[j].string[i][k] == ',')
                        putc('\\', file);
                    putc(some_table->columns[j].string[i][k], file);
                }
            } else if (some_table->columns[j].number[i] != 0)
                fprintf(file, "%f", some_table->columns[j].number[i]);
            putc(',', file);
        }
        putc('\n', file);

    }


    fclose(file);

}

DataTable_t *init_DT(Field_t user_fields[MAXCOLS], Column cols[MAXCOLS])
{

    // init pointer
    DataTable_t *myTable = (DataTable_t *) calloc(1, sizeof(DataTable_t));

    for (int i = 0; i < MAXCOLS; i++)
    {

        // assign all from columns
        myTable->fields[i] = user_fields[i];
        myTable->columns[i] = cols[i];

        int count = 0;

        // count meaningful rows
        while (strncmp(myTable->columns[i].string[count], "", 1) != 0 ||
               myTable->columns[i].number[count] != 0)
        {
            count++;
        }

        // store amount of meaningful rows in actual_rows
        myTable->fields[i].actual_rows = count;
    }

    return myTable;
}

void deinitDT(DataTable_t *some_table) { free(some_table); }

void display_header(DataTable_t *some_table)
{
    puts("\n\n");
    for (int i = 0;
         i < sizeof(some_table->fields) / sizeof(some_table->fields[0]); i++)
    {
        printf("%-10s\t", some_table->fields[i].name);
    }

    printf("\n");

    for (int i = 0; i < MAXCOLS; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("-");
        }
    }

    printf("\n");
}

void showDT(DataTable_t *some_table)
{
    display_header(some_table);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0;
             j < sizeof(some_table->fields) / sizeof(some_table->fields[0]); j++)
        {
            switch (some_table->fields[j].type)
            {
                case FLOAT:
                    if (some_table->columns[j].number[i] != 0)
                        printf("%-10.4f\t", some_table->columns[j].number[i]);
                    else
                        printf("%*s\t", -10, "-");
                    break;

                case STRING:
                    if (strlen(some_table->columns[j].string[i]) != 0)
                        printf("%-10.10s\t", some_table->columns[j].string[i]);
                    else
                        printf("%*s\t", -10, "-");
                    break;
            }
        }

        printf("\n");
    };

    // print ...'s
    for (int i = 0; i < MAXCOLS; ++i)
    {
        printf("%-10s\t", "...");
    }
}

DataTable_t *projectDT(DataTable_t *some_table, int m, int n, int x, int y)
{
    int row_offset, col_offset = 0;
    DataTable_t *projectedDT = (DataTable_t *) calloc(1, sizeof(DataTable_t));

    for (int i = m; i <= n; i++)
    {

        row_offset = 0;
        projectedDT->fields[col_offset] = some_table->fields[i];

        for (int j = x; j <= y; j++)
        {
            switch (projectedDT->fields[i].type)
            {
                case STRING:
                    strcpy(projectedDT->columns[col_offset].string[row_offset],
                           some_table->columns[i].string[j]);
                    break;

                case FLOAT:
                    projectedDT->columns[col_offset].number[row_offset] = some_table->columns[i].number[j];
                    break;
            }
            row_offset++;
        }
        col_offset++;
    }
    return projectedDT;
}

void mutateDT(DataTable_t *some_table, int column, void (*some_function)(double *num)) {
    for (int i = 0; i < some_table->fields[column].actual_rows; i++) {
        some_function(&some_table->columns[column].number[i]);
    }
}
