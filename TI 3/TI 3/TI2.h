#ifndef _TI2_NEW_LAB
#define _TI2_NEW_LAB

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
typedef double type;
typedef type * arr;
typedef arr * matr;

arr new_arr(int size);
matr new_matr(int m, int n);
void del_matr(matr a, int m);
void read_arr(arr a, int n);
void read_matr(matr a, int m, int n);
void printf_arr(arr a, int n);
void printf_matr(matr a, int m, int n);
type comp_info(arr a);
type comp_ent(arr a, int n);
type comp_p(arr a, int n);
type comp_q(matr a, int m, int j);
type p_A_and_B(matr a, int m, int n);
void characteristic(matr a, int m, int n);

void form_1(matr a, int m, int n);
void form_2(matr a, int m, int n);
int  test();

#endif // !_TI2_NEW_LAB