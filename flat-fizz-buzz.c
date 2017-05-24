#include <stdio.h>

int main(void) {
	for (int i = 0; i <= 100; i++)
		printf(i % 3 ? "" : "Fizz")|
		printf(i % 5 ? "" : "Buzz")?
		printf("\n"):
		printf("%i\n", i);
}
