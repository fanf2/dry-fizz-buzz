#include <stdio.h>

int main() {
  for (int i = 0;; i++)
    printf(printf("%s%s"
      , i % 3 ? "" : "Fizz"
      , i % 5 ? "" : "Buzz"
      ) ? "%.*s\n" : "%i%s\n", i, "");
}
