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

void merge(int array[], int head, int mid, int tail);
void mergeSort(int array[], int head, int tail);
void printArray(int arr[], int n);

void mergeSort(int array[], int head, int tail)
{
    if (head >= tail)
    {
        return;
    }
    else
    {
        int mid = head + (tail - head) / 2;
        mergeSort(array, head, mid);
        mergeSort(array, mid + 1, tail);
        merge(array, head, mid, tail);
    }
}

void merge(int array[], int head, int mid, int tail)
{

    int firstHalfIndex = 0;
    int secondHalfIndex = 0;
    int sortedMergeIndex = head;

    int x = mid - head + 1;
    int w = tail - mid;

    int HEAD[x], TAIL[w];

    for (int i = 0; i < x; i++)
        HEAD[i] = array[head + i];

    for (int j = 0; j < w; j++)
        TAIL[j] = array[mid + 1 + j];

    while (firstHalfIndex < x && secondHalfIndex < w)
    {
        if (HEAD[firstHalfIndex] <= TAIL[secondHalfIndex])
        {
            array[sortedMergeIndex] = HEAD[firstHalfIndex];
            firstHalfIndex++;
        }
        else
        {
            array[sortedMergeIndex] = TAIL[secondHalfIndex];
            secondHalfIndex++;
        }
        sortedMergeIndex++;
    }

    while (firstHalfIndex < x)
    {
        array[sortedMergeIndex] = HEAD[firstHalfIndex];
        firstHalfIndex++;
        sortedMergeIndex++;
    }

    while (secondHalfIndex < w)
    {
        array[sortedMergeIndex] = TAIL[secondHalfIndex];
        secondHalfIndex++;
        sortedMergeIndex++;
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[100000];
    int counter = 0;

    while (cin >> array[counter])
    {
        counter++;
    }
    mergeSort(array, 0, counter - 1);

    printArray(array, counter);

    return 0;
}