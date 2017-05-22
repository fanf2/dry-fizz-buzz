#include <stdio.h>

int main(void) {
  for (int i = 0; i <= 100; i++)
    printf(printf("%s%s"
      , i % 3 ? "" : "Fizz"
      , i % 5 ? "" : "Buzz"
      ) ? "%.*s\n" : "%i%s\n", i, "");
}
