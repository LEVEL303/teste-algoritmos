#include <stdio.h>

void increment(int *v) {
    (*v)++;
}

int main() {
    int a = 5;
    increment(&a);
    printf("%d", a);
}