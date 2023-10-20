#include <stdio.h>

int main() {
  int i = 0;
  while (1) {
    printf("Iterazione %d\n", i);
    printf("Premi Invio per continuare...\n");
    while (getchar() != '\n');
    i++;
  }
  return 0;
}
