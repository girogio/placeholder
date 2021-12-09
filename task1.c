#include <stdio.h>
#include <stdlib.h>
#include "task1.h"

int main() {

    int *array, *reversed_array, array_length;
    vf_pair_t *pairs;

    array = (int *) malloc(MAX * sizeof(int));
    reversed_array = (int *) malloc(MAX * sizeof(int));
    pairs = (vf_pair_t *) malloc(MAX * sizeof(vf_pair_t));


    int choice = 0;
    while (choice != 5) {

        print_menu(&choice);

        switch (choice) {
            case 1:
                array_length = init_array(array);
                break;
            case 2:
                display(array, array_length);
                break;
            case 3:
                reverse(array, reversed_array, array_length);
                display(reversed_array, array_length);
                break;
            case 4:
                for (int i = 0; i < array_length; i++) {
                    pairs[i].frequency = -1;
                }
                frequency(array, pairs, array_length);
                display_frequencies(pairs, array_length);
                break;
            case 5:
                printf("Bye!");
            default:
                break;
        }

    }
    return 0;
}

void print_menu(int *choice) {
    printf("\n1. Initialize the array\n2. Display the array\n3. Reverse the array\n4. Display frequencies of entries in array\n5. Exit\n> ");
    scanf("%d", choice);
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
    for (int i = 0; i < array_length; i++) {
        printf("\t\t{\n");
        jprint("offset", i, 'y');
        jprint("value", input_array[i], 'n');
        printf("\n\t\t},\n\n");
    }
    printf("\t]\n}");
}

void reverse(int *array_a, int *array_b, int length) {
    int start = 0;
    int end = length - 1;
    while (end >= 0) {
        array_b[start] = array_a[end];
        start++;
        end--;
    }
}

void frequency(int *array, vf_pair_t *pairs, int length) {
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
    printf("{\n\t\"array\": [\n");
    int offset = 0;
    for (int i = 0; i < array_length; i++) {
        if (pairs[i].frequency != 0) {
            printf("\t\t{\n");
            jprint("offset", offset++, 'y');
            jprint("value", pairs[i].value, 'y');
            jprint("frequency", pairs[i].frequency, 'n');
            printf("\n\t\t},\n\n");
        }
    }
    printf("\t]\n}");
}

void jprint(char *label, int value, char comma) {
    if (comma == 'y') {
        printf("\t\t\t\"%s\": \"%02d\",\n", label, value);
    } else if (comma == 'n') {
        printf("\t\t\t\"%s\": \"%02d\"", label, value);
    }
}
