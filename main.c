#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct arr {
    int count;
    int values[];
};

struct arr *arr_create(int count, int mod) {
    struct arr *new = malloc(sizeof(struct arr) + count * sizeof(int));
    new->count = count;
    for(int i = 0; i < count; ++i) {
        new->values[i] = rand() % mod;
    }
    return new;
}

void arr_free(struct arr *this) {
    free(this);
}

int main(void) {
    struct arr *arr = arr_create(10, 100);
    arr_free(arr);
}
