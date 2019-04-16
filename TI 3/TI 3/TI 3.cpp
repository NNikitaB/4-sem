// TI 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <fstream>
#include <iostream>
using  namespace std;
const int M = 50;
enum boold { FALSE, TRUE };
typedef struct alfavit
{
	type p;
	string sim;
}Alf;

int Compare_Types(const  void * a, const  void * b);//ф  сравнения 
int Search_Middle(Alf * a, int size1, int size2);//поиск середины
int F_Scan(istream &f, Alf * a, int size);
int F_Print(ostream &f, Alf * a, int size);
void Create_Tree(tnode *root, Alf *a, int size1,int size2);//создание дерева кодов
void razm(enum boold *a, int n, int* b, int m, int i, Alf * A, Alf * BI_ARR, int N);
/* создание размешений n по m с позиции i ,размещения записываютс в  BI_ARR(вначале пуст ,но память выделена) размера N
   (вспомогательные a -лог массив и b -мвсиив куда записываутся индексы текущего размещения
*/
int razm_is_povtor(Alf *a, int n, int par,Alf * BI_ARR, int N);
/* создание размешений n по par с размещения записываютс в  BI_ARR(вначале пуст ,но память выделена) размера N
   a -базовый массив эл. и вероятностей
*/
void Fano(istream& f, ostream& out, map <string, string>& Map_Table, char len, Alf * a, int N);
///считывает из f послед. символов размера len ,
///ищет эту послед в массиве и равеняет ее кодом 

int Compare_Types(const  void * a, const  void * b) {
	Alf arg1 = *(const  Alf *)a;
	Alf arg2 = *(const  Alf *)b;

	if (arg1.p < arg2.p)  return  1;
	if (arg1.p > arg2.p)  return  -1;
	return  arg1.sim > arg2.sim ?1:-1;//точно ли та к а не  >
}
int F_Print(ostream &f, Alf * a, int size) {
	for (int i = 0; i < size; i++) {
		f << a[i].sim ;
		f << "= ";
		f << a[i].p;
		f << " \n";
	}
	return 0;
}
int F_Scan(istream &f, Alf * a, int size) {
//	char buf ;
	
	for (int i = 0; i < size; i++) {
		f >> a[i].sim; f.ignore(1, ' ');
		//f >> buf;
		//cout << a[i].sim;
		f >> a[i].p;
	}
	return 0;
}
int Search_Middle(Alf * a, int size1, int size2) {
	type tm1 = 0.0, tm2 = 0.0,rez = 9999999;
	int i,t=size1+1;
	for (i = size1; i < size2-1; i++)
	{
		tm1 += a[i].p;
		for (int j = i + 1; j < size2; j++)
			tm2 += a[j].p;
		if (abs(tm1-tm2)<rez ) {
			rez = abs(tm1 - tm2);
			t = i+1 ;
		}
		tm2 = 0.0;
	}
	return t ;//возврав начала 2-го множ
}
void Create_Tree(tnode *root, Alf *a, int size1, int size2) {
	type sum1 = 0.0;
	if ( (size2 - size1 == 2) ){ addtree(root, a[size1].sim, 0); addtree(root, a[size1 + 1].sim, 1); return; }
	
	int index = Search_Middle(a, size1, size2)+1       -1;
	if ((size2 - size1 >2)) {
		if ((index - size1) == 1) { addtree(root, a[size1].sim, 0); addtree(root, a[size1+1].sim, 1); Create_Tree(root->right, a, size1 +1, size2); return; }
		if ((size2 - index) == 0) { addtree(root, a[size2 - 1].sim, 1); addtree(root, a[size1].sim, 0); Create_Tree(root->left, a, size1, size2-1); return; }
	}
	if ((index - size1) > 1) { addtree(root, a[size1].sim, 0); Create_Tree(root->left, a, size1, index); }
	if ((size2 - index) >= 1) { addtree(root, a[size1+1].sim, 1); Create_Tree(root->right, a, index, size2); }
}


int z = 0;//не забываем глобал переменную
void razm(enum boold *a, int n, int* b, int m, int i, Alf *A , Alf * BI_ARR, int N)
{
	for (int j = 0; j < n; ++j)
	{
		if (a[j])
		{
			b[i] = j;
			if (i < m - 1)
			{
				//a[j] = FALSE;
				razm(a, n, b, m, i + 1,A,BI_ARR,N);
				//a[j] = TRUE;
			}
			else
			{
				//printf("{ ");
				type tmp = 1.0;
				if (z < N) {
					
					for (int h = 0; h < m; ++h) {
						BI_ARR[z].sim += A[b[h]].sim;
						tmp *= A[b[h]].p;
					}
					BI_ARR[z++].p = tmp;
				}
					//printf("%i ", b[h]);
				//printf("}\n");
			}
		}
	}
}
int razm_is_povtor(Alf *a,int n,int par, Alf * BI_ARR,int N)
{
	enum boold * arr =(enum boold *) new enum boold[N];//log array
	int * b = new int[par];
	for (int i = 0; i < N; ++i)arr[i] = TRUE;
	razm(arr, n, b, par, 0,a, BI_ARR,N);
	delete []arr;
	delete []b;
	return 0;
}

void Fano(istream& f, ostream& out, map <string, string>& Map_Table,char len,Alf * a ,int N) {
	
	//char *s = (char *)new char[len+1];
	signed char c,size=0;
	string st,tmp_st;
	do {
		st.clear();
		for (int i = 0; i < len && !f.eof(); i++) {
			c = '\0';
			f >> c;
			if (c != '\n' && c != '\0')st.push_back(c);
		}
		//cout << st ;
		if (!st.empty() ) {
			auto it = Map_Table.find(st);
			//if (it != Map_Table.end()) out << it->second << " ";
			if (it != Map_Table.end()) tmp_st += it->second ;
		}
		
	} while (!f.eof());

	if (!st.empty() && st.size() < len) {
		while (st.size()< len)//пока не заполнится последняя грамма добавлять  сивол мин цены
		{
			st += a[len-1].sim;
			++size;
		}
		auto it = Map_Table.find(st);
		if (it != Map_Table.end()) tmp_st += it->second;
	}


	int ss = sizeof(char) * 8;
	vector <signed char> t1(ss), t2(ss);
	for (int j = 0; j < ss; j++) {
		t1[j] =  ((signed char)len >> j & 1) + '0';
		t2[j] =  ((signed char)size  >> j & 1)  +'0';
	}
	for (int j = 0; j < ss; j++) { out << t1[j] ;}
	for (int j = 0; j < ss; j++) { out << t2[j] ;}

	 out << tmp_st << endl;//len-размер блока   size кол-во add символов
}

void Decode_Fano(struct tnode *root, istream& f, ostream& out) {
	signed char gramm = 0, len = 0;
	char c;
	string st;
	struct tnode *tmp_root = root;


	int ss = sizeof(char) * 8;
	vector <signed char> t1(ss), t2(ss);
	for (int j = 0; j < ss; j++) { f >> t1[j]; }
	for (int j = 0; j < ss; j++) { f >> t2[j]; }
	
	for (int j = 0; j < ss; j++) {
		gramm |= (t1[j] - '0')<< j;
		len |= (t2[j] - '0') << j;
	}
	while (!f.eof() )
	{
		while (!f.eof() && tmp_root->left != NULL && tmp_root->right != NULL) {
			c = '5';
			f >> c;
			if (c == '0')tmp_root = tmp_root->left;
			else if (c == '1')tmp_root = tmp_root->right;
		}

		if(tmp_root->left ==  NULL && tmp_root->right == NULL )st += tmp_root->word;
		tmp_root = root;
	}
	if (!st.empty() && 0 < len) {for (signed char j = 0; j < len; j++)	st.pop_back();  }
	out << st << endl ;
}

//in_name_fail -файл с вероятностями и сисволами
//out_name_fail- файл для вывода закодированной последовательности
//decod_name_fail -файл для декодировки
int test1(const  char const  *in_name_fail, const  char const  *out_name_fail, const  char const  *decod_name_fail) {
	int RAZM = 2;
	std::ifstream Fail(in_name_fail, ios::in);
	istream *inpt = &Fail;
	if (!Fail.is_open()) inpt = &cin, cerr << "LOL no open fail\n";
	istream &in = *inpt;

	std::ofstream Fail_o(out_name_fail, ios::out);
	ostream *outpt = &Fail_o;
	if (!Fail_o.is_open()) outpt = &cout, cerr << "LOL no open fail out\n";
	ostream &out = *outpt;

	cout << "Ведите кол-во грамм\n";
	in >> RAZM;
	int count = 0;
	cout << "Ведите размер послед\n";
	in >> count;
	if (count <= 0) cerr << "Ошибка в размере кол-ва символов алфавита";
	Alf * Arr = (Alf *)new Alf[count];
	F_Scan(in, Arr, count);

	qsort(Arr, count, sizeof(Alf), Compare_Types);
	struct tnode *root = (struct tnode *)new struct tnode;
	root->left = NULL;
	root->right = NULL;
	//	addtree(root, Arr->sim,0);
	int bi_gramm = pow(count, RAZM);
	Alf * BI_ARR = (Alf *)new Alf[bi_gramm];
	razm_is_povtor(Arr, count, RAZM, BI_ARR, bi_gramm);
	//F_Print(cout, BI_ARR, bi_gramm);
	std::cout << "Hello World!\n";
	qsort(BI_ARR, bi_gramm, sizeof(Alf), Compare_Types);
	F_Print(cout, BI_ARR, bi_gramm);
	std::cout << "\n";
	std::cout << "count =" << bi_gramm << '\n';

	double ver = 0.0;
	for (int i = 0; i < bi_gramm; i++)ver += BI_ARR[i].p;
	if (fabs(1.0000 - ver) > 0.000000000000001) { cerr << "sum not 1  p=";  cerr.precision(15);  cerr << ver << "\n"; return 1; }
	Create_Tree(root, BI_ARR, 0, bi_gramm);
	//treeprint(root);

	string *st = (string *) new string;
	map <string, string> Map_Table;
	treeprint_in_Map(root, Map_Table, st);
	
	
	for (auto it = Map_Table.begin(); it != Map_Table.end(); it++) {
		cout << it->first << '=' << it->second << '\n';
	}

	Fano(in, out, Map_Table, RAZM,Arr,count);//ввыод в файд вместо cout



	std::ifstream F_decod(decod_name_fail, ios::in);
	istream *F_decodpt = &F_decod;
	if (!F_decod.is_open()) F_decodpt = &cin, cerr << "LOL no open fail\n";
	istream &F_decodpt_in = *F_decodpt;
	Decode_Fano(root, F_decodpt_in, cout);

	delete[]BI_ARR;
	delete[]Arr;
	freemem(root);

}

int main()
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	test1("TItest.txt","shifr1.txt", "s1.txt");
	z = 0;
	test1("TItest2.txt", "shifr2.txt", "s2.txt");
	return 0;
}
