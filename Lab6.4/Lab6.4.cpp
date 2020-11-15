#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void SumMI(int a[], const int size);
void SumMR(int a[], const int size,int i,int sum);

int NMAXI(int a[], const int size);
int NMINI(int a[], const int size);
int NMAXR(int a[], const int size, const int i, int max, int num);
int NMINR(int a[], const int size, const int i, int min, int num);

void DIFI(int a[], const int size, int x, int y);
void DIFR(int a[], const int size, int i, int s, int x, int y);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE, D;
    cout << "Введіть розмір масиву a[]:"; cin >> SIZE;
    int* a = new int[SIZE];

    cout <<endl<< "a[] = ";
    for (int i = 0; i < SIZE; i++)
    {
    int p = SIZE * 2;
    a[i] = -SIZE + rand() % p;
    cout << a[i] << " ";
    }
    cout << endl;

    cout << "Спосіб 1(ітераційний):" << endl;

    cout << "Сума від`ємних елементів масиву: ";
    SumMI(a, SIZE);
    int nmaxi = NMAXI(a,SIZE);
    cout << "Номер масимального елементу: " <<nmaxi<< endl;
    int nmini = NMINI(a, SIZE);
    cout << "Номер мінімального елементу: " <<nmini << endl;
    cout << "Добуток елементів, які задовільняють умову: ";
    DIFI(a, SIZE, nmaxi, nmini);
    cout << endl;

    cout << "Спосіб 2(рекурсивний):" << endl;
    cout << "Сума від`ємних елементів масиву: ";
    SumMR(a, SIZE,0,0);
    int nmaxr = NMAXR(a, SIZE,0,0,0);
    cout << "Номер масимального елементу: " << nmaxr << endl;
    int nminr = NMINR(a, SIZE,0,0,0);
    cout << "Номер мінімального елементу: " << nmini << endl;
    cout << "Добуток елементів, які задовільняють умову: ";
    DIFR(a, SIZE,0,1, nmaxr, nminr);
    cout << endl;
    return 0;
}
//ітераційний спосіб
void SumMI(int a[], const int size)
{
    int sum = 0;
    for(int i=0;i<size;i++)
        if (a[i] < 0) { sum = sum + a[i]; }
    cout << sum<<endl;
}
int NMAXI(int a[], const int size)
{
    int max = -size-10;
    int num;
    for (int i = 0; i < size; i++)
        if (a[i] > max) { max = a[i]; num = i + 1; }
    return num;
}
int NMINI(int a[], const int size)
{
    int min = size + 10;
    int num;
    for (int i = 0; i < size; i++)
        if (a[i] < min) { min = a[i]; num = i + 1; }
    return num;
}
void DIFI(int a[], const int size, int x, int y)
{
    int nmin;
    int nmax;
    int S = 1;
    if (x > y) { nmax = x - 1; nmin = y - 1; }
    else{ nmax = y - 1; nmin = x - 1; }
    for (int i = 0; i < size; i++)
    {
        if (i >= nmin && i <= nmax) { S = S * a[i]; }
    }
    cout << S << endl;
}
//рекурсивний спосіб
void SumMR(int a[], const int size, int i, int sum)
{
    if (i >= size) { cout << sum << endl; }
    else 
    {
        if (a[i] <= 0) 
        {
            SumMR(a, size, i + 1, sum + a[i]);
        }
        else { SumMR(a, size, i + 1, sum); }
    }
}
int NMAXR(int a[], const int size,const int i,int max,int num)
{
    if (i < size) {
        {if (a[i] > max) { max = a[i]; num = i + 1; }
        NMAXR(a, size, i + 1, max, num);
        }
    }
    else {return num;}
}
int NMINR(int a[], const int size, const int i, int min, int num)
{
    if (i < size) {
        {if (a[i] < min) { min = a[i]; num = i + 1; }
        NMAXR(a, size, i + 1, min, num);
        }
    }
    else { return num; }
}
void DIFR(int a[], const int size, int i, int s,int x,int y)
{
    int nmin;
    int nmax;
    if (x > y) { nmax = x - 1; nmin = y - 1; }
    else { nmax = y - 1; nmin = x - 1; }
    if (i >= size) { cout << s << endl; }
    else
    {
        if (i >= nmin && i <= nmax)
        { 
            DIFR(a, size, i + 1, s*a[i],x,y);
        }
        else { DIFR(a, size, i + 1, s,x,y); }
    }
}

