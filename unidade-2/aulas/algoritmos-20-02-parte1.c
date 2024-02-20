#include <stdio.h>

int imprimir() {
    int index; // 1 vez: c1
    int n = 10; // 1 vez: c2
    for(index = 0; index < n; index++) { // n vezes: c3
        printf("%d\n", index); // n vezes: c4 
    }
}

/* 
T(Max) = c1 + c2 + c3*n + c4*n
T(Max) = c1 + c2 + (c3 + c4)*n
T(Max) = a + b*n
T(Max) = b*n
T(n) = n : tempo de execução linear.

Big-O
T(n) = O(n)
*/