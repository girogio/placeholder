//
// Created by grongo on 12/6/21.
//

#include <stdio.h>

int init_array(int *input_array);

void display(int *input_array, int array_length);

int main() {
    int *array[200];
    //init_array(array);
    display(array, 2);
    return 0;
}


int init_array(int *input_array) {
    int length = 0;
    printf("How many integers should this array hold? [0-200]\n> ");
    while (length <= 0 | length > 200) {
        scanf("%d", &length);

        if (length < 0 | length > 200) {
            printf("Invalid input. Try again.\n> ");
        }
    }

    for (int i = 0; i < length; i++) {
        printf("Enter integer #%d\n> ", i + 1);
        scanf("%d", &input_array[i]); // place value directly in the array at index i
    }
    return length;
}

void display(int *input_array, int array_length) {
    printf("{\n\t\"array\": [\n");
    for (int i = 0; i < array_length; ++i) {
        printf("\t\t{\n");
        printf("\t\t\t\"offset\": \"%d\"\n", i);
        printf("\t\t\t\"value\": \"%d\"", input_array[i]);
        printf("\n\t\t},\n\n");
    }
    printf("\t]\n}");
}