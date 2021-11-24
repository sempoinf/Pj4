#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


void swap(int i, int j, int* arr) { // Функция для i на j, а j на i (из массива arr)
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void qs(int, int, int*);   // сигнатура ( это для того, чтобы можно было написать функцию после main() )



//  функция быстрой сортировки
void qs(int low, int high, int* array) {   // Приниает на вход индекс первого элемента, последнего, а также массив, который нужно отсортировать
    
    int mid = (int)(low + ((high - low) / 2));  // mid - это центр или опорный элемент
    int l, r;           // l - индекс левого элемента, r - правого
   
    l = low;
    r = high;
    do {
        while (array[l] < array[mid])       // Ищем элемент слева от опрного, который > опорного
            l++;
        if (l != mid) {         // Если нашли (не дошли до опроного)
            while (array[r] > array[mid])   // Ищем элемент справа от опрного, который < опорного
                r--;

            if (r > mid) {                                            // Стандартная ситуация (есть эл. слева от опорного, который > опорного и справа от опорного, котрый < опорного)
                swap(l, r, array);                                    // Просто меняем их местами
            }
            else {                                                   // r = mid, т.е. слева нашли, справа не нашли
                swap((mid - 1), l, array);                           // меняем левый от mid с эл. > mid
                swap(mid, (mid - 1), array);                         // после меняем эл. > mid (он слева от mid) с mid
                r = mid -= 1;                                        // mid подвинулся, r был равен mid => он тоже должен подвинуться
            }
        }
        else {                                      // l = mid
            while (array[r] > array[mid])
                r--;
            if (r != l) {                                           // Слева не нашли, справа нашли
                swap((mid + 1), r, array);                          // Тоже, что и выше, но в обратную сторону
                swap(mid, (mid + 1), array);
                l = mid += 1;
            }
        }
    } while (l < r);                                              // Если l и r не встретились в mid (l != r) то значит мы не все элементы проверили и нужна еще итерация
  /*  for (int i = 0; i < 19; i++) {
        printf("%d ", (array[i]));                                // Печатает массив, отсортированный по опорному эллементу
    }
    printf("\n");
    */

    if ((high - low) > 1) {                 // high - low = 1 означает, что наш массив состоит из 2 эл. (т.к. array[0] - 1ый эл., [1] - 2ой
 // для массива из 2 эл. все что написано выше поставит меньший эл. слева, а больший справа т.е. этот массив будет отсортирован в порядке возрастнания
        qs(low, mid, array);        // вызываем функцию заново, но говорим ей сортировать левую (от mid) часть
        qs(mid, high, array);       // правую (от mid) часть
    }  // фунуция будет вызываться рекурсивно, в конце получим отсортированный массив

}

int* arr_gen(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    return arr;
}

int main() {
    int size;
    scanf("%d", &size);
    int* array = (int*)malloc(size * sizeof(int));

    srand(time(NULL));
    array = arr_gen(size);
    
    clock_t start = clock();
    qs(0, (size - 1), array);
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);
    printf("\n");
   // for (int i = 0; i < size; i++) {       
        //printf("%d\n", (array[i]));}

        
    
}
