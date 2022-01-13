#include "task2a.h"

void triple(double *num);


int main() {

    Field_t fields[] = {
            {"Label0", FLOAT},
            {"Label1", FLOAT},
            {"Label2", FLOAT},
            {"Label3", STRING},
            {"Label4", STRING},
            {"Label5", STRING},
    };

    Column cols[] = {
            {.number = {1, 2, 3, 4.6, 5.9, 4.6}},
            {.number = {1.3, 2.2, 3.4, 4.2, 5.8, 4.6}},
            {.number = {11.3, 1112.2, 31114, 11112, 51.18, 4.16}},
            {.string = {"some", "strings", "are", "longer", "than", "others"}},
            {.string = {"lol", "easy", "peasy", "aaaaaanother, one", "abbb", "sadasda"}},
            {.string = {"tomato", "blueberry", "banana", "orange", "apple", "asdad", "XDZ"}}
    };

    DataTable_t *mytable = init_DT(fields, cols);

    showDT(mytable);

    DataTable_t *projected_DT = projectDT(mytable, 2, 5, 0, 5);

    showDT(projected_DT);

    mutateDT(mytable, 2, triple);

    showDT(mytable);

    exportDT(mytable, "output.csv");

    deinitDT(mytable);
}

void triple(double *num) {
    *num *= 3;
}