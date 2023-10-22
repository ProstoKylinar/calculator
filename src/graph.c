#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculation.h"
#include "function.h"

#define WIDTH 80
#define HEIGHT 25

void output_graf(const double* results);

int main() {
    char* s = malloc(80 * sizeof(char));
    double* results = malloc(80 * sizeof(double));
    int leng = input(s);
    char* p = malloc((leng * 2) * sizeof(char));
    correct_buff(s, &leng);
    leng = parcing(s, p, leng);
    function_values(p, leng, results);
    output_graf(results);
    free(s);
    free(p);
    free(results);
    return 0;
}

void output_graf(const double* results) {
    for (double i = -1; i <= 1; i += (2.0 / HEIGHT)) {
        for (int j = 0; j < WIDTH - 1; j++) {
            if (results[j] >= i - 0.04 && results[j] <= i + 0.04) {
                printf("*");
            } else {
                printf(".");
            }
        }
        if (results[WIDTH - 1] >= i - 0.04 && results[WIDTH - 1] <= i + 0.04) {
            printf("*\n");
        } else {
            printf(".\n");
        }
    }
}