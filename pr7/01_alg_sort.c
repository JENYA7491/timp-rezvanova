#include <stdio.h>
#include <stdlib.h>
FILE *file_sort;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *array, int left, int right, int size) {
    int pivot = array[right - 1];
    int index = left - 1;
    for (int j = left; j < right; j++) {
        if (array[j - 1] <= pivot) {
            index++;
            swap(&array[index - 1], &array[j - 1]);
            for (int k = 0; k < size; k++) {
                if (k != 0)
                fprintf(file_sort, " ");
                fprintf(file_sort, "%d", array[k]);
            }
            fprintf(file_sort, "\n");
        }
    }
    swap(&array[index], &array[right - 1]);
    return index + 1;
}

int quicksort(int *array, int left, int right, int size) {
    if (left < right) {
        int quick = partition(array, left, right, size);
        quicksort(array, left, quick - 1, size);
        quicksort(array, quick + 1, right, size);
    }
    return 0;
}

// формирование кучи
void heapify(int *numbers, int root, int bottom, int size) {
    int max; // индекс максимального потомка
    int done = 0;
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done)) {
      if (root * 2 == bottom)    // если на последнем уровне
      max = root * 2;    // запоминаем левого потомка
      // иначе запоминаем больший потомок из двух
      else if (numbers[root * 2] > numbers[root * 2 + 1])
      max = root * 2;
      else
      max = root * 2 + 1;
      // если вершина меньше максимального потомка
      if (numbers[root] < numbers[max]) {
      swap(&numbers[max], &numbers[root]);
      root = max;
      for (int k = 0; k < size; k++) {
          if (k != 0)
          fprintf(file_sort, " ");
          fprintf(file_sort, "%d", numbers[k]);
      }
      fprintf(file_sort, "\n");
      }
      else
      done = 1; // пирамида сформирована
    }
}

// Пирамидальная сортировка
void heapSort(int *numbers, int array_size, int n) {

  // Формирование низа пирамиды
  for (int i = (array_size / 2); i >= 0; i--)
    heapify(numbers, i, array_size - 1, n);

  // Сортировка остальных элементов
  for (int i = array_size - 1; i >= 1; i--) {
    swap(&numbers[0], &numbers[i]);
    heapify(numbers, 0, i - 1, n);
  }
}

void read_array(int *a, int *b, int n) {
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[i] = x;
        b[i] = x;
    }
}

void print_array(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if (i != n-1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);
    int *array_1 = malloc(size * sizeof(int));
    int *array_2 = malloc(size * sizeof(int));
    read_array(array_1, array_2, size);

     // создание файла для чтения или записи. Если существует, то содержимое очищается.
    file_sort = fopen("quicksort.log", "w+");
    fclose(file_sort);
    file_sort = fopen("quicksort.log", "w+");
    quicksort(array_1, 1, size, size);
    for (int k = 0; k < size; k++) {
        if (k != 0)
        fprintf(file_sort, " ");
        fprintf(file_sort, "%d", array_1[k]);
    }
    fclose(file_sort);
    file_sort = fopen("heapsort.log", "w+");
    fclose(file_sort);
    file_sort = fopen("heapsort.log", "w+");
    heapSort(array_2, size, size);
    for (int k = 0; k < size; k++) {
        if (k != 0)
        fprintf(file_sort, " ");
        fprintf(file_sort, "%d", array_1[k]);
    }
    fclose(file_sort);
    print_array(array_1, size);
    return 0;
}


