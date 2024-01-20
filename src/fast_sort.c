#include <stdio.h>

int input(int *a);
void output(int *a);
void sort(int *a);
int perm(int *a, int l, int r);
void quick(int *a, int l, int r);
void bunch(int *a, int n, int i);
void heap(int *array);

int main() {
    int data[10], data1[10];
    int k = input(data);
    if (k == 0) {
        for (int i = 0; i < 10; i++)
            data1[i] = data[i];
        quick(data, 0, 9);
        output(data);
        printf("\n");
        heap(data1);
        output(data1);
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

int perm(int *a, int l, int r) {
    int x = a[r];
    int less = l;
    int t;
    for (int i = l; i < r; i++) {
        if (a[i] <= x) {
            t = a[less];
            a[less] = a[i];
            a[i] = t;
            ++less;
        }
    }
    t = a[less];
    a[less] = a[r];
    a[r] = t;
    return less;
}

void quick(int *a, int l, int r) {
  if (l < r) {
    int q = perm(a, l, r);
    quick(a, l, q - 1);
    quick(a, q + 1, r);
  }
}

void heap(int *a) {
    for (int i = 4; i >= 0; i--)
        bunch(a, 10, i);

    for (int i = 9; i >= 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;

        bunch(a, i, 0);
    }
}

void bunch(int *a, int n, int i) {
    int lar = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if ((l < n) && (a[l] > a[lar]))
        lar = l;
    if ((r < n) && (a[r] > a[lar]))
        lar = r;
    if (lar != i) {
        int t = a[i];
        a[i] = a[lar];
        a[lar] = t;
        bunch(a, n, lar);
    }
}
