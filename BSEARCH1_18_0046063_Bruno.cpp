// BRASILIA 08/03/2021
// BRUNO SANGUINETTI REGADAS DE BARROS
// MATRICULA 180046063
// PROJETO E ANALISE DE ALGORITMOS - 117536 
// PROF. DR. JAN CORREA
// UNIVERSIDADE DE BRASILIA

// https://www.spoj.com/users/brunosrb/

#include <iostream>
using namespace std;

int binarySearch(long long int array[], long long int n, int x)
{
    int base = 0;
    int top = x - 1;
    int rtrn = -1;
    while (base <= top)
    {
        int mid = (base + top) / 2;
        if (array[mid] == n)
        {
            rtrn = mid;
            top = mid - 1;
        }
        else if (array[mid] > n)
        {
            top = mid - 1;
        }
        else
        {
            base = mid + 1;
        }
    }
    return rtrn;
}
int main()
{
    int n, q;

    scanf("%d%d", &n, &q);

    long long int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    while (q--)
    {
        long long int aux;

        scanf("%lld", &aux);

        int rtrn = binarySearch(a, aux, n);
        if (rtrn == -1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", rtrn);
        }
    }
    return 0;
}