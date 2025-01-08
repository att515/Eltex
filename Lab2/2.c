#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    int *array;
    int *reverse;
    while(1) {
        printf("Введите размер массива (1 - 100): ");
        if (scanf("%d", &N) == 1 && getchar() == '\n') {
            if (N >= 1 && N <= 100) {
                array = (int*)malloc(N * sizeof(int));
                if (array == NULL) {
                    printf("Ошибка выделения памяти\n");
                    return 1;
                }
                printf("Изначальный массив: ");
                for (int i = 0; i < N; i++) {
                    array[i] = i + 1;
                    printf("%4d", array[i]);
                }
                reverse = (int*)malloc(N * sizeof(int));
                if (reverse == NULL) {
                    printf("Ошибка выделения памяти\n");
                    return 1;
                }
                printf("\nОбратный массив: ");
                for (int i = 0; i < N; i++) {
                    reverse[i] = array[N - i - 1];
                    printf("%4d", reverse[i]);
                }
                free(array);
                free(reverse);
                return 0;
            }
            if (N == 0) {
                printf("Введен 0, пустой массив\n");
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
