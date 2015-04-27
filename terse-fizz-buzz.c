#include <stdio.h>

int main() {
  for (int i = 0;; i++)
    printf(printf("%s%s"
      , i % 3 ? "" : "Fizz"
      , i % 5 ? "" : "Buzz"
      ) ? "\n" : "%i\n", i);
}
