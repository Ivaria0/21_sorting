#include <stdio.h>

int input(int *a, int *n, int *c);
void output(int *a, int n);
void cycle(int *a, int n, int c);

int main() {
    int data[10], n, c;
    input(data, &n, &c);
    cycle(data, n, c);
    output(data, n);

    return 0;
}

int input(int *a, int *n, int *c) {
    float v;
    *n = 0;
    int b = scanf("%f", &v);
    if (((int)v == v) && (b == 1) && (v <= 10) && (v > 0)) {
        *n = v;
        int *p;
        p = a;
        for (int i = 0; i < *n; i++) {
            b = scanf("%f", &v);
            if (((int)v == v) && (b == 1))
                *p++ = v;
            else
                *n = -1;
        }
        b = scanf("%f", &v);
        if (((int)v == v) && (b == 1))
            *c = v;
        else
            *n = -1;
    }
    return 0;
}

void output(int *a, int n) {
    if (n > 0) {
        int *p;
        p = a;
        for (int i = 0; i < n; i++)
            printf("%d ", *p++);
        printf("\b");
    } else {
        printf("n/a");
    }
}

void cycle(int *a, int n, int c) {
    int *p;
    if (n > 0) {
    int q[10];
    p = a;
    for (int i = 0; i < n; i++)
        q[i] = p[i];
    if (c / n != 0)
        c = c % n;
    if (c < 0)
        c = n + c;
    for (int i = 0; i < n - c; i++)
        p[i] = q[i + c];
    for (int i = n - c; i < n; i++)
        p[i] = q[i + c - n];
    }
}
