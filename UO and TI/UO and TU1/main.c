////#include <stdio.h>
////#include <stdlib.h>
////
////int main()
////{
////    printf("Hello world!\n");
////    return 0;
////}
//
//
//
///*
//t_arr matr_in_a(t_arr b,int m,int n,t_typ_d a)//матр на число
//{
//    t_arr g= create_matr(m,n);
//    size_t i,j;
//    for(i=0;i<m;i++)
//        for(j=0;j<n;j++)
//           *(*(g+i)+j)=a* *(*(b+i)+j);
//    return i==m && j==n?g:NULL;
//}
//t_arr matr_in_matr(t_arr a,int m1,int n1,t_arr b,int m2,int n2,int* m3,int* n3)//маир на матр
//{
//    t_arr c=NULL;
//    if(n1!=m2) return c;
//    c=create_matr(m1,n2);
//    size_t i,j;
//    *m3=m1;
//    *n3=n2;
//    for(i=0;i<m1;i++)
//        for(j=0;j<n2;j++)
//        {
//            c[i][j]=0;
//            size_t p,q;
//            for(p=0,q=0;(p<m1 && q<n2);p++,q++)
//                c[i][j]+=a[i][q]* b[p][j];
//        }
//
//  return c;
//}
//t_arr matr_add_matr(t_arr a,int m1,int n1,t_arr b,int m2,int n2)//складывает матрицу а с б
//{
//    if(m1!=m2 || n1!=n2) return 0;
//    t_arr g=a;// create_matr(m1,n1);
//    size_t i,j;
//    for(i=0;i<m1;i++)
//        for(j=0;j<n1;j++)
//           *(*(g+i)+j)=*(*(a+i)+j)+ *(*(b+i)+j);
//    return i==m1 && j==n1?g:NULL;
//}
//t_arr matr_subt_matr(t_arr a,int m1,int n1,t_arr b,int m2,int n2)//вычитает матрицу б из a
//{
//    if(m1!=m2 || n1!=n2) return 0;
//    t_arr g= create_matr(m1,n1);
//    size_t i,j;
//    for(i=0;i<m1;i++)
//        for(j=0;j<n1;j++)
//            *(*(g+i)+j)=*(*(a+i)+j)- *(*(b+i)+j);
//    return i==m1 && j==n1?g:NULL;
//}
//
//void swap(t_arr a,int m1, int n1,int m2,int n2)
//{
//    t_typ_d tmp=a[m1][n1]; a[m1][n1]=a[m2][n2]; a[m2][n2]=tmp;
//}
//*/
//#include <stdio.h>
//#include <malloc.h>
//#include <math.h>
//double ***AllBasis;
//int AllBasisPointer=0;
//
//#define EPS 0.01
//typedef double** t_arr;
//typedef double* t_d;
//typedef double t_typ_d;
//typedef struct af {t_arr ar;int * c;}mas;
//
//int el_eqvel(t_typ_d a, t_typ_d b){return fabs(a-b)<EPS;}
//
//void del_matr(t_arr a,int m,int n)
//{
//    for(int i=0;i<m;i++) free(a[i]);
//    free(a);
//}
//
//
//void matr_copy(t_arr a,t_arr b,int m,int n)//матр на число
//{
//    size_t i,j;
//    for(i=0;i<m;i++)
//        for(j=0;j<n;j++)
//           *(*(b+i)+j)= *(*(a+i)+j);
//}
//
//int serch_max_el(t_arr a,int m,int n,int i,int *p)//в p вернет номер max эл,и вернет 1 ссли строка не нулевая
//{
//    size_t t=0;
//    t_typ_d tmp=fabs(a[i][0]);
//    for(size_t j=1;j<n;j++)
//        if(fabs(a[i][j])>tmp)tmp=fabs(a[i][j]),t=j;
//    *p=t;
//    return EPS<tmp || -EPS>tmp;
//}
//
//void del_str_mart(t_arr a,int * m ,int * n,int i)
//{
//    if(i<*m)
//    {
//         free(a[i]);
//         *m-=1;
//         for(int k=i;k<*m;k++)a[i]=a[i+1];
//    }
//}
//
//void shag(t_arr a,int  m ,int  n,int i1,int j1)
//{
//    t_typ_d tmp=a[i1][j1];
//    if(!el_eqvel(tmp,0.0))
//    {
//
//
//    for(size_t j=0;j<n;j++)a[i1][j]/=tmp;
//
//    for(size_t i=0;i<m;i++)
//        if(i!=i1)
//            {
//                tmp=a[i][j1];
//                for(size_t j=0;j<n;j++)
//                   a[i][j]=a[i][j]-a[i1][j]*tmp;
//            }
//    }
//}
//
//int metd_gays_zhord(t_arr a,int * m ,int * n,int * c)
//{
//    int r=0;
//    for(size_t i=0;i<*m;i++)
//        if(serch_max_el(a,*m,*n-1,i,&r) )
//          {
//             if(!el_eqvel(0.0,a[i][r])){shag(a,*m,*n,i,r);c[i]=r;}
//          }
//        else if( el_eqvel(a[i][*n-1],0.0)){del_str_mart(a,m,n,i);--i;}
//             else {printf("НЕТ РЕШЕНИЯ\n");return -1;}
//
//        return 0;
//}
//
//
//
//
//void divis(int n, double *a, double b){
//    //if(b!=0){
//        for (int i = 0; i < n; ++i) a[i] = a[i] / b;
//    //}else{
//    //    printf("Div on 0!!!");
//    //}
//}
//
//void mulandadd(int n, double *a, double c, double *b){
//    for (int i = 0; i < n; ++i) b[i] = a[i] * c + b[i];
//}
//
//void replaceAonB(int n, double *a, double *b){
//    for (int i = 0; i < n; ++i) a[i] = b[i];
//}
//
//int checkFreedom(int m, int k, double **a){ //Проверяем является ли k-ая переменная свободной
//    int ones=0, nulls=0;
//    for (int i=0;i<m;i++) {
//        if(a[i][k]==1){
//            ones++;
//        }else if (a[i][k]==0){
//            nulls++;
//        }
//    }
//    return ((ones==1)&&(nulls==m-1));
//}
//
//void printmatr(int n, int m, double** a){
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j)
//            printf("%-7.2g", a[i][j]);
//        puts("");
//    }
//}
//
//double **Operation(int n, int m, int x, int y, int* new_n, int* new_m, double **a){ //x и y задают разрешающий элемент, возвращается новый базис
//    double **copy_a; // Выделяем память под новый базис
//    copy_a=malloc(m*sizeof(double*));
//    for (int i = 0; i < m; ++i) {
//        copy_a[i]=malloc(n*sizeof(double));
//        for (int j=0;j<n;j++) {
//            copy_a[i][j] = a[i][j];
//        }
//    }
//
//    divis(n, copy_a[y], copy_a[y][x]);
//
//    for (int i = 0; i < m; ++i) {
//        int AccessPosition=-1, onePosition = -1, notNullPosition = -1;
//        for (int j = 0; j < n; ++j) {
//            if ((copy_a[i][j] == 1)&&(!checkFreedom(m,j,copy_a))) {
//                onePosition = j;
//                break;
//            }else if((copy_a[i][j] != 0)&&((copy_a[i][j] != 1))){
//                notNullPosition = j;
//                break;
//            }
//        }
//
//        if (onePosition != -1) {
//            AccessPosition = onePosition;
//        } else {
//            AccessPosition = notNullPosition;
//            divis(n, copy_a[i], copy_a[i][notNullPosition]);
//        }
//
//        for (int j = 0; j < m; ++j)
//            if (i != j)
//                mulandadd(n, copy_a[i], -copy_a[j][AccessPosition], copy_a[j]);
//    }
//
//    for (int i = 0; i < m; ++i) { // избавляемся от нулевых строк
//        int numberFounded=0;
//        for (int j = 0; j < n; ++j) {
//            if (a[i][j] != 0) {
//                numberFounded = 1;
//                break;
//            }
//        }
//        if(!numberFounded){
//            for (int j = i+1; j < m; ++j) {
//                replaceAonB(n,copy_a[j-1],copy_a[j]);
//            }
//            (m)--;
//        }
//    }
//
//    *new_n = n;
//    *new_m = m;
//    return copy_a;
//}
//
//int GaussJordan(int n, int *m, double **a) { // Возвращается кол-во строк в полученной матрице
//    int step = 0;
//    for (int i = 0; i < *m; ++i) {
//        int AccessPosition=-1, onePosition = -1, notNullPosition = -1;
//        for (int j = 0; j < n; ++j) {
//            if (a[i][j] == 1) {
//                onePosition = j;
//                break;
//            }else if(a[i][j] != 0){
//                if((notNullPosition!=-1)&&(abs(a[i][j])>abs(a[i][notNullPosition]))){
//                }else {
//                    notNullPosition = j;
//                }
//            }
//        }
//
//        if (onePosition != -1) {
//            AccessPosition = onePosition;
//        } else {
//            AccessPosition = notNullPosition;
//            divis(n, a[i], a[i][notNullPosition]);
//        }
//        for (int j = 0; j < *m; ++j)
//            if (i != j)
//                mulandadd(n, a[i], -a[j][AccessPosition], a[j]);
//        printf("\n---- %3i-th step -----\n",++step);
//        printmatr(n, *m,a);
//    }
//
//    for (int i = 0; i < *m; ++i) { // избавляемся от нулевых строк
//        int numberFounded=0;
//        for (int j = 0; j < n; ++j) {
//            if (a[i][j] != 0) {
//                numberFounded = 1;
//                break;
//            }
//        }
//        if(!numberFounded){
//            for (int j = i+1; j < *m; ++j) {
//                replaceAonB(n,a[j-1],a[j]);
//            }
//            (*m)--;
//        }
//    }
//    return n;
//}
//
//int equalsMatrix(int m, int n, double **a,double **b) //Возвращает true, если матрица A==B
//{
//    for (int i=0; i<m; i++) {
//        for (int j=0; j<n; j++) {
//            //printf("%f\n", abs(a[i][j]-b[i][j]));
//            if(fabs(a[i][j]-b[i][j])>0.0001){
//                return 0;
//            }
//        }
//    }
//    return 1;
//}
//
//int findBasis(int m, int n, double **a) //Возвращает true, если матрица A уже есть среди массива AllBasis найденных базисов
//{
//    for (int i=0;i<AllBasisPointer;i++){
//        //printmatr(n, m, a); puts("\n\n");
//        //printmatr(n, m, AllBasis[i]); puts("\n------------");
//        if(equalsMatrix(m,n, a, AllBasis[i])){
//            return 1;
//        }
//    }
//    return 0;
//}
//
//void writeAllBasis(int n, int m, double **a){
//    int new_n, new_m;
//    for (int i=0;i<m;i++)
//        for (int j=0;j<n;j++)
//            if(!checkFreedom(m,j,a)){
//                //printmatr(n, m,AllBasis[0]);
//                double **NewBasis = Operation(n,m,j,i,&new_n,&new_m,a);
//                //printmatr(n, m,AllBasis[0]);
//                if(!findBasis(new_m,new_n,NewBasis)){
//                    printmatr(new_n, new_m, NewBasis); puts("\n------------");
//                    //printmatr(n, m,AllBasis[0]);
//                    AllBasis[AllBasisPointer++]=NewBasis;
//                    //printmatr(n, m,AllBasis[0]);
//                    writeAllBasis(new_n, new_m, NewBasis);
//                }
//            }
//}
//
//int main() {
//    int n, m;
//    double **a;
//    scanf("%i %i", &n, &m);
//    a=malloc(m*sizeof(double*));
//    for (int i = 0; i < m; ++i) a[i]=malloc(n*sizeof(double));
//    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) scanf("%lf", &a[i][j]);
//
//    //GaussJordan(n, &m, a);
//int *c=calloc(m+n,sizeof(int));
//metd_gays_zhord(a,&m,&n,c);
//    printf("\n---- Result -----\n");
//    printmatr(n, m,a);
//    printf("\n\n------ All Basis ------\n\n");
//
//    AllBasis = calloc(pow(n,2),sizeof(double**));
//    AllBasis[AllBasisPointer++]=a;
//    writeAllBasis(n, m, a);
//
//    return 0;
//}
