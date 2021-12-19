#define MAX 200

char ERR_MSG[] = "\nERROR: No array is initialized.\n" ;

typedef struct {
    int value;
    int frequency;
} vf_pair_t;

typedef enum { false, true } boolean;

void print_menu(int *choice);

int init_array(int *array);

void reverse(const int *array_a, int *array_b, int length);

void display(int *array, int array_length);

void frequency(const int *array, vf_pair_t  *pairs, int array_length);

void display_frequencies(vf_pair_t *pairs, int array_length);

void jprintf(char *attribute, int value, boolean comma);

void clear_term();





