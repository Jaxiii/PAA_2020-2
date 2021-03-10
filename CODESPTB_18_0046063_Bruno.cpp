// BRASILIA 08/03/2021
// BRUNO SANGUINETTI REGADAS DE BARROS
// MATRICULA 180046063
// PROJETO E ANALISE DE ALGORITMOS - 117536 
// PROF. DR. JAN CORREA
// UNIVERSIDADE DE BRASILIA 

// https://www.spoj.com/users/brunosrb/
// https://github.com/Jaxiii/PAA_2020-2_TRABALHO_1

#include <iostream>
using namespace std;

int insertionSort(int array[], int n)
{
    int counter = 0;
    for (int i = 1, j, k; i < n; i++)
    {
        k = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > k)
        {
            array[j + 1] = array[j];
            j = j - 1;
            counter++;
        }
        array[j + 1] = k;
    }
    return counter;
}

void printCounter(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " " << endl;
    }
}

int main()
{
    int array[100000];
    int alt_number[5];
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> array[j];
        }

        alt_number[i] = insertionSort(array, n);
    }

    printCounter(alt_number, t);

}