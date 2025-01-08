#include <stdio.h>
#include <locale.h>

void print_binary(unsigned int number) {
    int size = sizeof(number) * 8;
    unsigned int mask = 1 << (size - 1);
    printf("Число в бинарном виде: ");
    for (int i = 0; i < size; i++){
        if ((number & mask) != 0) {
            printf("1");
        }
        else {
            printf("0");
        }
        if ((i + 1) % 8 == 0){
            printf(" ");
        }
        mask >>= 1;
    }
    printf("\n");
}

void find_number_units(unsigned int number) {
    int count = 0;
    printf("Количество единиц в числе бинарного вида: ");
    int size = sizeof(number) * 8;
    unsigned int mask = 1 << (size - 1);
    for (int i = 0; i < size; i++){
        if ((number & mask) != 0) {
            count++;
        }
        mask >>= 1;
    }
    printf("%d", count);
    printf("\n");
}

void replace_byte(unsigned int number, int byte_number, int number_replace_byte) {
    unsigned int mask = ~(255 << byte_number * 8);
    number = (number & mask) | (number_replace_byte << byte_number * 8);
    printf("Число после замены: %d \n", number);
    print_binary(number);
}

int main() {
    setlocale(LC_ALL, "Russian");
    while(1) {
        printf("Введите целое положительное или отрицательное число: ");
        unsigned int number = 0;
        if (scanf("%d", &number) == 1 && getchar() == '\n') {
            if (number > 0) {
                print_binary(number);
                find_number_units(number);
                while (1) {
                    printf("Введите номер байта который хотите поменять (от 0 до 3): ");
                    int byte_number = 0;
                    int number_replace_byte = 0;
                    if (scanf("%d", &byte_number) == 1 && getchar() == '\n') {
                        if (byte_number >= 0 && byte_number < sizeof(number)) {
                            while(1) {
                                printf("Введите число на которое хотите заменить данный байт (от 0 до 255): ");
                                if (scanf("%d", &number_replace_byte) == 1 && getchar() == '\n') {
                                    if (number_replace_byte >= 0 && number_replace_byte <= 255) {
                                        replace_byte(number, byte_number, number_replace_byte);
                                        return 0;
                                    }
                                    else {
                                        printf("Некорректное число\n");
                                    }
                                }
                            }
                        }
                        else {
                            printf("Некорректное число\n");
                        }
                    }
                    else {
                        while (getchar() != '\n');
                        printf("Некорректный номер байта (от 0 до 3)\n");
                    }
                }
            }
            else if (number < 0) {
                print_binary(number);
                return 0;
            }
            else {
                printf("Вы ввели 0, введите положительное или отрицательное число\n");
                print_binary(number);
                find_number_units(number);
            }
        }
        else {
            while (getchar() != '\n');
            printf("Некорректное число\n");
        }
    }
}
