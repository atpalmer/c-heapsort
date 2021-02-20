#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct arr {
    int count;
    int values[];
};

struct arr *arr_create(int count, int mod) {
    srand(time(NULL));
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

void arr_print(struct arr *this) {
    printf("[ ");
    for(int i = 0; i < this->count; ++i)
        printf("%d ", this->values[i]);
    printf("]\n");
}

void _swap(int data[], int i1, int i2) {
    int tmp = data[i1];
    data[i1] = data[i2];
    data[i2] = tmp;
}

#define L_CHILD(head)   ((((head) + 1) * 2) - 1)
#define R_CHILD(head)   ((head) + 1)

void _max_heapify(int data[], int head, int count) {
    if(L_CHILD(head) < count) {
        _max_heapify(data, L_CHILD(head), count);
        if(data[L_CHILD(head)] > data[head]) {
            _swap(data, L_CHILD(head), head);
            _max_heapify(data, L_CHILD(head), count);
        }
    }

    if(R_CHILD(head) < count) {
        _max_heapify(data, R_CHILD(head), count);
        if(data[R_CHILD(head)] > data[head]) {
            _swap(data, R_CHILD(head), head);
            _max_heapify(data, R_CHILD(head), count);
        }
    }
}

void arr_max_heapify(struct arr *this) {
    _max_heapify(this->values, 0, this->count);
}

int main(void) {
    struct arr *arr = arr_create(10, 100);
    arr_print(arr);
    arr_max_heapify(arr);
    arr_print(arr);
    arr_free(arr);
}
