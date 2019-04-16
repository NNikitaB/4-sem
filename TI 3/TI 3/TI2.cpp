#include "TI2.h"
#include "pch.h"

arr new_arr(int size)
{
	arr a = (arr)calloc(size, sizeof(type));
	return a;
}
matr new_matr(int m, int n)
{
	matr a = (matr)calloc(m, sizeof(arr));
	for (int i = 0; i < m; ++i)a[i] = (arr)calloc(n, sizeof(type));
	return a;
}
void del_matr(matr a, int m)
{
	for (int i = 0; i < m; ++i)free(a[i]);
	free(a);
}
void read_arr(arr a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%lf", a + i);
	}
}
void read_matr(matr a, int m, int n)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf_s("%lf", *(a + i) + j);
}
void printf_arr(arr a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("p%i=%f ", i, a[i]);
}
void printf_matr(matr a, int m, int n)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			printf("p%i=%f ", i, a[i][j]);
}


type comp_info(arr a)
{
	static type ln2 = log(2);
	type j = log(*a) / ln2;
	return -j;
}

type comp_ent(arr a, int n)
{
	type H = 0.0;
	for (int i = 0; i < n; ++i)
		if (*(a + i) != 0.0)H += *(a + i)*comp_info(a + i);
	return H;
}
type comp_p(arr a, int n)
{
	type p = 0.0;
	for (int i = 0; i < n; ++i)p += a[i];
	return p;
}
type comp_q(matr a, int m, int j)
{
	type q = 0.0;
	for (int i = 0; i < m; ++i)q += a[i][j];
	return q;
}
type p_A_and_B(matr a, int m, int n)
{
	type H = 0.0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != 0.0)H += a[i][j] * comp_info(*(a + i) + j);
	return H;
}
void characteristic(matr a, int m, int n)
{
	arr P_arr = new_arr(m);
	arr Q_arr = new_arr(n);
	type H_A_B = p_A_and_B(a, m, n);
	for (int i = 0; i < m; ++i)
		P_arr[i] = comp_p(a[i], n);
	for (int i = 0; i < n; ++i)
		Q_arr[i] = comp_q(a, m, i);
	type H_A = comp_ent(P_arr, m);
	type H_B = comp_ent(Q_arr, n);
	type H_AdelB = H_A_B - H_A;
	type H_BdelA = H_A_B - H_B;
	type I_A_B = H_A - H_AdelB;

	printf("Энтропия источника H(A)=%f\n", H_A);
	printf("Энтропия приемника H(B)=%f\n", H_B);
	printf("условная энтропия H(A/B)=%f\n", H_AdelB);
	printf("условная энтропия H(B/A)=%f\n", H_BdelA);
	printf("взаимная энтропия H(A,B)=%f\n", H_A_B);
	printf("взаимная информация I(A,B)=%f\n", I_A_B);
	printf("\n");
	free(P_arr);
	free(Q_arr);
}

void form_1(matr a, int m, int n)
{
	printf("Введите табл p(a_i)\n");
	arr p_arr = new_arr(m);
	read_arr(p_arr, m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] *= p_arr[i];

	free(p_arr);
}
void form_2(matr a, int m, int n)
{
	printf("Введите табл p(b_i)\n");
	arr p_arr = new_arr(n);
	read_arr(p_arr, n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] *= p_arr[j];

	free(p_arr);
}

int  test()
{
	setlocale(LC_ALL, "Rus");
	int h = 1;
	while (h)
	{
		int n = 0, m = 0;
		int f = 3;
		printf_s("Введите Форму записи табл 1 , 2 или 3 \n");
		scanf_s("%i", &f);
		printf_s("Введите размер табл m n\n");
		scanf_s("%i", &m);
		scanf_s("%i", &n);
		matr a = new_matr(m, n);
		int fff = 0;
		do
		{
			read_matr(a, m, n);
			if (f == 1)
			{
				type tmp = 0.0;
				for (int i = 0; i < m; ++i)
				{
					tmp = 0.0;
					for (int j = 0; j < n; ++j)
						tmp += a[i][j];
					if (1.0 != tmp)printf("Ошибка сумма   вероятностей в  %i-й строки не равна 1\n", i), fff = 1;
				}

				form_1(a, m, n);

			}
			else if (f == 2)
			{
				type tmp = 0.0;
				for (int i = 0; i < m; ++i)
				{
					tmp = 0.0;
					for (int j = 0; j < n; ++j)
						tmp += a[j][i];
					if (1.0 != tmp)printf("Ошибка сумма  вероятностей в %i-м столбце не равна 1\n", i), fff = 1;
				}

				form_2(a, m, n);
			}
			else
			{
				type tmp = 0.0;
				for (int i = 0; i < m; ++i)
					for (int j = 0; j < n; ++j)
						tmp += a[j][i];
				if (1.0 != tmp)printf("Ошибка сумма  всех вероятностей не равна 1\n"), fff = 1;
			}
		} while (fff);

		characteristic(a, m, n);
		//printf_matr(a,m,n);


		del_matr(a, m);
		printf("Введите 0 чтобы закончить вычисления\n");
		scanf_s("%i", &h);
	}
	return 0;
}