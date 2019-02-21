#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1
#define EPS 0.01
#include <locale.h>

int PEREST;
typedef double** t_arr;
typedef double* t_d;
typedef double t_typ_d;
typedef struct af {t_arr ar;int * c;}mas;
int el_eqvel(t_typ_d a, t_typ_d b){return fabs(a-b)<EPS;}

void del_matr(t_arr a,int m,int n)
{
    for(int i=0;i<m;i++) free(a[i]);
    free(a);
}
t_arr create_matr(int m,int n)
{
    t_arr a;
    a=(t_arr)calloc(sizeof(t_d),m);
    for(int i=0;i<m;i++) a[i]=(t_d)calloc(sizeof(t_typ_d),n);
    return a;
}
void write_matr(t_arr a,int m,int n)
{
    size_t i,j;
    for(i=0;i<m;i++)
        {for(j=0;j<n;j++)
           printf("%.2lf ",a[i][j]);
          printf("\n");
        }
}
int read_matr(t_arr a,int m,int n)
{
    size_t i,j;
    printf("Write matr in line with space \n ");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%lf",(*(a+i)+j));
    return i==m && j==n;
}

void matr_copy(t_arr a,t_arr b,int m,int n)//матр на число
{
    size_t i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
           *(*(b+i)+j)= *(*(a+i)+j);
}

int serch_max_el(t_arr a,int m,int n,int i,int *p)//в p вернет номер max эл,и вернет 1 ссли строка не нулевая
{
    size_t t=0;
    t_typ_d tmp=fabs(a[i][0]);
    for(size_t j=1;j<n;j++)
        if(fabs(a[i][j])>tmp)tmp=fabs(a[i][j]),t=j;
    *p=t;
    return EPS<tmp || -EPS>tmp;
}

void del_str_mart(t_arr a,int * m ,int * n,int i)
{
    if(i<*m)
    {
         free(a[i]);
         *m-=1;
         for(int k=i;k<*m;k++)a[i]=a[i+1];
    }
}

void shag(t_arr a,int  m ,int  n,int i1,int j1)
{
    t_typ_d tmp=a[i1][j1];
    if(!el_eqvel(tmp,0.0))
    {


    for(size_t j=0;j<n;j++)a[i1][j]/=tmp;

    for(size_t i=0;i<m;i++)
        if(i!=i1)
            {
                tmp=a[i][j1];
                for(size_t j=0;j<n;j++)
                   a[i][j]=a[i][j]-a[i1][j]*tmp;
            }
    }
}

int metd_gays_zhord(t_arr a,int * m ,int * n,int * c)
{
    int r=0;
    for(size_t i=0;i<*m;i++)
        if(serch_max_el(a,*m,*n-1,i,&r) )
          {
             if(!el_eqvel(0.0,a[i][r])){shag(a,*m,*n,i,r);c[i]=r;}
          }
        else if( el_eqvel(a[i][*n-1],0.0)){del_str_mart(a,m,n,i);--i;}
             else {printf("НЕТ РЕШЕНИЯ\n");return -1;}

        return 0;
}

unsigned long num_of_com4(int n, int m)
{
    unsigned long k = n - m;
    if (m > k)
        m = k;
    if (!m)
        return 1;
    unsigned long akk = k = n - m + 1;
    k++;
    for (unsigned long i = 2; i <= m; i++, k++)
        akk = akk / i * k + akk % i * k / i;
    return akk;
}

int search_el(int *a,int n,int x)
{
    unsigned i=0;
    while(i<n && x!=a[i])++i;
    return i<n;
}

int search_mas(mas *ms,int f ,int * a,int r,int j,int n)
{
    int t[n];
    for(unsigned  i=0;i<n;++i)t[i]=a[i];
    t[r]=j;
    int j1=0,j2=0;
    while(j1<f)
    {
        j2=0;
        while(j2<n && search_el(ms[j1].c,n,t[j2]))++j2;
        if(j2>=n)return 1;

        ++j1;
    }
return 0;
}
void mn(mas *ms,int m,int n,int count)
{
    unsigned f=0,p=0,i=0,kl=0;
    //write_matr(ms[f].ar,m,n)
   // while(f<count-1 || (kl=0))
    while( (p<count-1) && p<=f)
    {

i=kl;
kl+=1;
        while(i<m)
    {
            for(unsigned  j=0;j<n-1;++j)
            {
                //if(j!=ms[f].c[i])
                   // if(!search_el(ms[p].c,n,j))
                        if(!search_mas(ms,f+1,ms[p].c,i,j,n))
                            if(!el_eqvel(1.0,ms[p].ar[i][j]) && !el_eqvel(0.0,ms[p].ar[i][j]))
                      {
                          printf("  %i  ************\n",f);
                       if(f<count-1){matr_copy(ms[p].ar,ms[f+1].ar,m,n);for(size_t r=0;r<n-1;++r)ms[p].c[r]=ms[f+1].c[r];++f;}
                       shag(ms[f].ar,m,n,i,j);
                       write_matr(ms[f].ar,m,n);
                       ms[f].c[i]=j;
// 1 3 1 5
//6 -2 1 5
                      }

                   }
                   ++i;
    }
//++i;
                   ++p;
            }
//write_matr(ms[f].ar,m,n);
    printf("  %i  ************END\n",f);
}
void opora(mas *ms,int * count,int m,int  n)
{
    int j=0;
    for(unsigned  i=0;i<*count;++i)
    {
        j=0;
        while(j<m && 0.0<ms[i].ar[j][n-1])++j;
        if(j<m)
            {
                //del_matr(ms[i].ar,m,n);
                //free(ms[i].c);
                ms[i].ar=ms[*count-1].ar;
                ms[i].c=ms[*count-1].c;
                *count-=1;
            }
    }
}
t_typ_d f_z(t_arr a,int * c,int m,int n)//n-1
{
    int tmp[n];
    t_typ_d rez=0.0;
    for(unsigned  i=0;i<n;++i)tmp[i]=1;

    for(unsigned  i=0;i<m;++i)rez+=tmp[i]*a[i][n];
    return rez;
}
void opt_opora(mas *ms,int coun,int m,int n)
{
    t_typ_d tmp=0.0,max=0.0;
    max=f_z(ms->ar,ms->c,m,n-1);tmp=max;
    int num=0;
    for(unsigned  i=1;i<coun;++i)
    {
        tmp=f_z(ms[i].ar,ms[i].c,m,n-1);
        if(tmp>max)max=tmp,num=i,printf("%.2lf\n",tmp);
    }
    printf("Opora\n");
    write_matr(ms[num].ar,m,n);
}
//5 -3 1 -1 4 5
//1 -2 3 4 -1 2
//5 -6 3 2 4 1
//2 -4 6 8 -2 4
int main()
{
    setlocale(LC_ALL, "Rus");
    int m,n;// printf("Введие %lu==========\n",num_of_com4(3,2));
    printf("Введие размер матрицы коэф через пробел m n \n");
    scanf("%i%i",&m,&n);
     t_arr a= create_matr(m,n);
     read_matr(a,m,n);
     int *c=calloc(m+n,sizeof(int));
     int coun= num_of_com4(n-1,m);
     metd_gays_zhord(a,&m,&n,c);

     printf("C_n=%i \n",coun);
     mas *ms=(mas *)calloc(coun,sizeof(mas));
     for(unsigned long i=1;i<coun;++i)ms[i].ar=create_matr(m,n),ms[i].c=calloc(m+n,sizeof(int));
     ms[0].ar=a;ms[0].c=c;
      write_matr(a,m,n);
     for(int y=0;y<n-1;++y)printf("*%i  *\n ",c[y]);
    mn(ms,m,n,coun);
    opora(ms,&coun,m,n);
    printf("******count matr%i\n",coun);

    opt_opora(ms,coun,m,n);
    return 0;
}
