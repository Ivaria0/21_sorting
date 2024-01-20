/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
	Функция получает массив данных
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int length, buffer[10];
    input(buffer, &length);
    output(buffer, length);
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    int flag = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            flag += 1;
        }
    }

    if (flag == 0)
        return -1;

    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int num = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[num] = buffer[i];
                num++;
            }
        }
    }
    return num;
}

void input(int *buffer, int *length) {
    float v;
    *length = 0;
    int b = scanf("%f", &v);
    if (((int)v == v) && (b == 1) && (v <= 10) && (v > 0)) {
        *length = v;
        int *p;
        p = buffer;
        for (int i = 0; i < *length; i++) {
            b = scanf("%f", &v);
            if (((int)v == v) && (b == 1))
                *p++ = v;
            else
                *length = -1;
        }
    }
}

void output(int *buffer, int length) {
    if (length > 0) {
        int numbers[10];
        int number = sum_numbers(buffer, length);
        if (number != -1) {
            printf("%d\n", number);
            int num = find_numbers(buffer, length, number, numbers);
            for (int i = 0; i < num; i++)
                printf("%d ", numbers[i]);
            printf("\b");
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}
