#include <stdio.h>
#include <stdlib.h>
#include "task1.h"

int main() {

    int *array, *reversed_array, array_length;
    vf_pair_t *pairs;

    array = (int *) malloc(MAX * sizeof(int));
    reversed_array = (int *) malloc(MAX * sizeof(int));
    pairs = (vf_pair_t *) malloc(MAX * sizeof(vf_pair_t));

    if (array == NULL | reversed_array == NULL | pairs == NULL) {
        return 1;
    }

    boolean is_array_init = false;

    clear_term();

    int choice = 0;
    while (choice != 5) {
        print_menu(&choice);
        switch (choice) {
            case 1:
                array_length = init_array(array);
                is_array_init = true;
                break;
            case 2:
                is_array_init ?
                display(array, array_length)
                              : print_err();
                break;
            case 3:
                is_array_init ?
                reverse(array, reversed_array, array_length),
                        display(reversed_array, array_length)
                              : print_err();
                break;
            case 4:
                is_array_init ?
                frequency(array, pairs, array_length),
                        display_frequencies(pairs, array_length)
                              : print_err();
                break;
            case 5:
                free(array);
                free(reversed_array);
                free(pairs);
                clear_term();
            default:
                break;
        }

    }
    return 0;
}

int init_array(int *input_array) {
    int length = 0;

    clear_term();
    printf("How many integers should this array hold? [1-200]\n> ");

    while (length <= 0 | length >= 200) {
        scanf("%d", &length);

        if (length <= 0 | length > 200) {
            printf("Invalid input. Try again.\n> ");
        }
    }

    for (int i = 0; i < length; i++) {
        printf("Enter integer #%d\n> ", i + 1);
        scanf("%d", &input_array[i]);
    }

    clear_term();

    return length;
}

void display(int *input_array, int array_length) {
    clear_term();
    printf("{\n%*s\"array\": [\n", 4, " ");
    for (int i = 0; i < array_length; i++) {
        printf("%*s{\n", 8, " ");
        jprintf("offset", i, true);
        jprintf("value", input_array[i], false);
        printf("\n%*s", 8, " ");
        if (i == array_length - 1)
            printf("}\n");
        else
            printf("},\n\n");
    }
    printf("%*s]\n}\n", 4, " ");
}

void reverse(const int *array_a, int *array_b, int length) {
    int start = 0;
    int end = length - 1;
    while (end >= 0) {
        array_b[start] = array_a[end];
        start++;
        end--;
    }
}

void frequency(const int *array, vf_pair_t *pairs, int length) {
    for (int i = 0; i < length; i++) {
        pairs[i].frequency = -1;
    }
    for (int i = 0; i < length; i++) {
        int count = 1;
        for (int j = i + 1; j < length; j++) {
            if (array[i] == array[j]) {
                count++;
                pairs[j].frequency = 0;
            }
        }
        if (pairs[i].frequency != 0) {
            pairs[i].frequency = count;
            pairs[i].value = array[i];
        }
    }
}

void display_frequencies(vf_pair_t *pairs, int array_length) {
    clear_term();
    printf("{\n%*s\"array\": [\n", 4, " ");
    int offset = 0;
    for (int i = 0; i < array_length; i++) {
        if (pairs[i].frequency != 0) {
            printf("%*s{\n", 8, " ");
            jprintf("offset", offset++, true);
            jprintf("value", pairs[i].value, true);
            jprintf("frequency", pairs[i].frequency, false);
            printf("\n%*s", 8, " ");
            if (i == array_length - 1)
                printf("}\n");
            else
                printf("},\n\n");
        }
    }
    printf("%*s]\n}\n", 4, " ");
}

void print_menu(int *choice) {
    printf("1. Initialize the array\n2. Display the array\n3. Reverse a copy of the array and display it\n4. Display frequencies of entries in array\n5. Exit\n> ");
    scanf("%d", choice);
}

void clear_term() {
    printf("\e[1;1H\e[2J");
}

void print_err() {
    printf("%s", ERR_MSG);
}

void jprintf(char *label, int value, boolean comma) {
    comma ?
        printf("%*s\"%s\": \"%02d\",\n", 12, " ", label, value)
    :   printf("%*s\"%s\": \"%02d\"", 12, " ", label, value);
}
