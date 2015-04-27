#include <stdbool.h>
#include <stdio.h>

typedef struct pred {
	bool (*pred)(int);
	const char *name;
} pred;

#include PTBL

static bool putsafe(const char *s) {
	return s != NULL && fputs(s, stdout) != EOF;
}

int main(void) {
	for (int i = 0; true; i++) {
		bool done = false;
		for (pred *p = ptbl; p < ptbl_end; p++)
			done |= putsafe(p->pred(i) ? p->name : NULL);
		printf(done ? "\n" : "%d\n", i);
	}
}
