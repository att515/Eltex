#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    int **matrix;
    while(1) {
        printf("Введите размер квадратной матрицы (1 - 100): ");
        if (scanf("%d", &N) == 1 && getchar() == '\n') {
            if (N >= 1 && N <= 100) {
                matrix = (int**)malloc(N * sizeof(int*));
                if (matrix == NULL) {
                    printf("Ошибка выделения памяти\n");
                    return 1;
                }
                for (int i = 0; i < N; i++) {
                    matrix[i] = (int*)malloc(N * sizeof(int));
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (i + j >= N - 1) {
                            matrix[i][j] = 0;
                        }
                        else {
                            matrix[i][j] = 1;
                        }
                        printf("%4d", matrix[i][j]);
                    }
                    if (i != N - 1) {
                        printf("\n");
                    }
                }
                for (int i = 0; i < N; i++) {
                    free(matrix[i]);
                }
                free(matrix);
                return 0;
            }
            else {
                printf("Некорректное число\n");
            }
        }
        else {
            while (getchar() != '\n');
            printf("Некорректное число\n");
        }
    }
    return 0;
}
