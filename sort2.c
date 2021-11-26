#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


#define SIZE 15 // мы предполагаем, что у нас есть 15 элементов в массиве

void counting_sort(int*, int*, int, int, int); //прототип функции, которая выполняет сортировку.

//void main()
//{
    //int given_array[SIZE] = { 100,82,87,91,87,97,91,90,82,80,97,100,99,80,88 }; //пример.

    //int max = 100; //наибольшее число в массиве, в данном случае 100.
   // int min = 80;  //наименьшее число в массиве, в данном случае 80.

   // int sorted_array[SIZE];
   // printf("\n");

   // counting_sort(given_array, sorted_array, SIZE, max, min);
//}

void counting_sort(int given_array[], int sorted_array[], int size, int max, int min)
{
    int length = max - min;
    int* counting_array = (int*)calloc((length + 1), sizeof(int));
    int k = 0;


    for (int i = 0; i <= length; i++)
    {
        counting_array[i] = 0; //инициализируем ячейки массива нулями
    }

    //подсчитываем количество вхождений каждого элемента исходного массива, складываем эти числа в массив.
    for (int j = 0; j < size; j++)
    {
        counting_array[given_array[j] - min] += 1;
    }

    //строим отсортированный массив
    while (k < size)
    {
        for (int i = 0; i <= length; i++)
        {
            for (int l = 0; l < counting_array[i]; l++)
            {
                sorted_array[k] = i + min;
                k++;
            }
        }
    }

    //отображаем отсортированный массив
    for (int i = 0; i < size; i++)
        printf("%d ", sorted_array[i]);
    printf("\n");
}


int* arr_gen(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    return arr;
}

int main() {

    int size, i,length;
    int min = 100001;
    int max = -1;
    scanf("%d", &size);
    int* array = (int*)malloc(size * sizeof(int));

    srand(time(NULL));
    array = arr_gen(size);
    for (i = 0; i < size; i++) {
        if (min > array[i]) { min = array[i]; }
        else if (max < array[i]) { max = array[i]; }

    }
    length = max-min;
    int* arr1;
    arr1 = (int*)malloc(length * sizeof(int));
    for (i = 0; i < max; i++)
        arr1[i] = 0;


    clock_t start = clock();
    counting_sort(array, arr1, size, max, min);
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);
    printf("\n");
    // for (int i = 0; i < size; i++) {       
         //printf("%d\n", (array[i]));}



}
