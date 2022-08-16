#include <stdio.h>

int mergesort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergesort(arr, inicio, meio);
        mergesort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

void merge(int arr[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int subA[n1], subB[n2];
    for (int i = 0; i < n1; i++)
    {
        subA[i] = arr[inicio + i];
    }
    for (int i = 0; i < n1; i++)
    {
        subB[i] = arr[meio + i];
    }
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (subA[i] <= subB[j])
        {
            arr[k] = subA[i];
            i++;
        }

        else
        {
            arr[k] = subB[j];
            j++;
        }
    }

    while(j < n2)
    {
        arr[k] = subB[j];
        j++;
        k++;
    }

    while(i < n1)
    {
        arr[k] = subA[i];
        k++;
        i++;
    }

}

int main()
{
    int arr[] = {3, 0, 7, 1, 5, 2, 4, 6}, tam = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, tam);
}