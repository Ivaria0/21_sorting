#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

int input(int *buff, int *len);
int check(int *buff1, int len1, int *buff2, int len2);
void output(int *result1, int result_length1, int *result2, int result_length2);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int len1, len2, buff1[LEN], buff2[LEN];
    input(buff1, &len1);
    input(buff2, &len2);
    int res_len1, res_len2, result1[LEN + 1], result2[LEN];
    sum(buff1, len1, buff2, len2, result1, &res_len1);
    sub(buff1, len1, buff2, len2, result2, &res_len2);
    output(result1, res_len1, result2, res_len2);
}

int input(int *buff, int *len) {
  char c, s;
  *len = 0;
  int *p;
  p = buff;
  do {
    scanf("%c%c", &c, &s);
    if (((s == ' ') || (s == '\n')) && (c >= '0') && (c <= '9')) {
      *p++ = (int)c - (int)'0';
      *len += 1;
    } else {
      *len = -1;
      return 1;
    }
  } while ((s != '\n') && (*len != -1));
  if (*len > LEN) {
    *len = -1;
    return 1;
  }
  return 0;
}

int check(int *buff1, int len1, int *buff2, int len2) {
  if ((len1 <= 0) || (len2 <= 0))
    return 0;
  if (len1 < len2)
    return 0;
  if (len1 == len2) {
    for (int i = 0; i < len1; i++) {
      if (buff1[i] > buff2[i]) {
        return 1;
      } else if (buff1[i] < buff2[i]) {
        return 0;
      }
    }
  }
  return 1;
}

void output(int *result1, int result_length1, int *result2, int result_length2) {
  if ((result_length1 > 0) && (result_length2 > 0)) {
    int *p1, *p2;
    p1 = result1;
    p2 = result2;
    for (int i = 0; i < result_length1; i++)
        printf("%d ", p1[i]);
    printf("\b\n");
    for (int i = 0; i < result_length2; i++)
        printf("%d ", p2[i]);
    printf("\b");
  } else {
    printf("n/a");
  }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
  if ((len1 > 0) && (len2 > 0)) {
    int p[LEN + 1];
    p[len1] = 0;
    *result_length = 0;
    int t;
    int r;
    if (len1 > len2)
      r = len1;
    else
      r = len2;
    for (int i = 0; i < r; i++) {
      if ((len1 - i - 1 >= 0) && (len2 - i - 1 >= 0)) {
        t = p[r - i] + buff1[len1 - i - 1] + buff2[len2 - i - 1];
        p[r - i] = t % 10;
        p[r - i - 1] = t / 10;
      } else if (len1 - i - 1 >= 0) {
        t = p[r - i] + buff1[len1 - i - 1];
        p[r - i] = t % 10;
        p[r - i - 1] = t / 10;
      } else if (len2 - i - 1 >= 0) {
        t = p[r - i] + buff2[len2 - i - 1];
        p[r - i] = t % 10;
        p[r - i - 1] = t / 10;
      }
    }
    int flag = 0;
    for (int i = 0; i <= len1; i++) {
      if ((flag == 1) || (p[i] != 0) || (i == len1)) {
        flag = 1;
        *result++ = p[i];
        *result_length += 1;
      }
    }
    if (*result_length > LEN)
      *result_length = -1;
  } else {
    *result_length = -1;
  }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
  if (check(buff1, len1, buff2, len2) == 1) {
    int p[LEN];
    int t;
    p[len1 - 1] = 0;
    *result_length = 0;
    for (int i = 1; i <= len2; i++) {
      t = p[len1 - i] + buff1[len1 - i] - buff2[len2 - i];
      if (t < 0) {
        p[len1 - i] = t + 10;
        p[len1 - i - 1] = -1;
      } else if (len1 - i > 0) {
        p[len1 - i] = t;
        p[len1 - i - 1] = 0;
      } else {
        p[len1 - i] = t;
      }
    }
    for (int i = len1 - len2 - 1; i > 0; i--) {
      t = p[i] + buff1[i];
      if (t < 0) {
        p[i] = t + 10;
        p[i - 1] = -1;
      } else {
        p[i] = t;
        p[i - 1] = 0;
      }
    }
    if (len1 > len2)
      p[0] = p[0] + buff1[0];
    else
      p[0] = p[0] + buff1[0] - buff2[0];
    int flag = 0;
    for (int i = 0; i < len1; i++) {
      if ((flag == 1) || (p[i] != 0) || (i == len1 - 1)) {
        flag = 1;
        *result++ = p[i];
        *result_length += 1;
      }
    }
  } else {
  *result_length = -1;
  }
}
