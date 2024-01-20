#include <stdio.h>

int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int data[10];
    int k = input(data);
    if (k == 0) {
        sort(data);
        output(data);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a) {
    float v = 0;
    int *p;
    p = a;
    int b;
    for (int i = 0; i < 10; i++) {
        b = scanf("%f", &v);
        if (((int)v == v) && (b == 1))
            *p++ = v;
        else
            return 1;
    }
    return 0;
}

void output(int *a) {
    int *p;
    p = a;
    for (int i = 0; i < 10; i++)
        printf("%d ", *p++);
    printf("\b");
}

void sort(int *a) {
    int *p;
    int t;
    for (int i = 0; i < 9; i++) {
        p = a;
        for (int j = 0; j < 9 - i; j++) {
            if (p[j] > p[j + 1]) {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
}
