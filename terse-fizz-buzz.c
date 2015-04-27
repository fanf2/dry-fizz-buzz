#include <stdio.h>
#include <err.h>

int main(void) {
  for (int n, i = 0;; i++)
    printf("%s%s%n",
	   i % 3 == 0 ? "Fizz" : "",
	   i % 5 == 0 ? "Buzz" : "",
	   &n), printf(n ? "\n" : "%i\n", i);
}
