#include <stdio.h>

void selection_sort(int array[], int length) {
  for (int i = 0; i < length - 1; i++) {
    // Trova il massimo elemento nel sottoarray non ancora ordinato
    int max_index = i;
    for (int j = i + 1; j < length; j++) {
      if (array[j] > array[max_index]) {
        max_index = j;
      }
    }

    // Scambia l'elemento massimo con il primo elemento del sottoarray non ancora ordinato
    int temp = array[i];
    array[i] = array[max_index];
    array[max_index] = temp;
  }
}

int main() {
  // Test della funzione con un array di esempio
  int array[] = {4, 2, 7, 1, 3, 6, 5};
  int length = sizeof(array) / sizeof(array[0]);
  selection_sort(array, length);

  // Stampa l'array ordinato
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}