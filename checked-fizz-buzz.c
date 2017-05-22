#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#include <err.h>

static bool
printif(bool p, const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	if(p) p = vprintf(fmt, ap) >= 0;
	va_end(ap);
	return(p);
}

int
main(void) {
	for(int i = 1; i <= 100; i++) {
		bool p = false;
		p |= printif(i % 3 == 0, "Fizz");
		p |= printif(i % 5 == 0, "Buzz");
		p |= printif(!p, "%d", i);
		if(!printif(p, "\n"))
			err(1, "write");
	}
	if(fflush(stdout) < 0)
		err(1, "write");
	return(0);
}
