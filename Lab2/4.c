#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    int **matrix;
    int left, right, top, bottom, value;
    while(1) {
        printf("Введите размер квадратной матрицы (1 - 100): ");
        if (scanf("%d", &N) == 1 && getchar() == '\n') {
            left = 0;
            right = N - 1;
            top = 0;
            bottom = N - 1;
            value = 1;
            if (N >= 1 && N <= 100) {
                matrix = (int**)malloc(N * sizeof(int*));
                if (matrix == NULL) {
                    printf("Ошибка выделения памяти\n");
                    return 1;
                }
                for (int i = 0; i < N; i++) {
                    matrix[i] = (int*)malloc(N * sizeof(int));
                }

                while (left <= right && top <= bottom) {
                    for (int i = left; i <= right; i++) {
                        matrix[top][i] = value++;
                    }
                    top++;
                    for (int i = top; i <= bottom; i++) {
                        matrix[i][right] = value++;
                    }
                    right--;
                    if (top <= bottom) {
                        for (int i = right; i >= left; i--) {
                            matrix[bottom][i] = value++;
                        }
                        bottom--;
                    }
                    if (left <= right) {
                        for (int i = bottom; i >= top; i--) {
                            matrix[i][left] = value++;
                        }
                        left++;
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        !!!
                        printf("%6d", matrix[i][j]);
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
