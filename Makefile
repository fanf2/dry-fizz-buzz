CFLAGS=	-pipe -O -g -std=c99 -pedantic \
	-Wall -Wextra -Wbad-function-cast -Wcast-align -Wcast-qual \
	-Wconversion -Wformat=2 -Winit-self -Winline -Wmissing-declarations \
	-Wmissing-prototypes -Wnested-externs -Wold-style-definition \
	-Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes \
	-Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings

all: dry-fizz-buzz-elf dry-fizz-buzz-hom blog.html \
     terse-fizz-buzz flat-fizz-buzz checked-fizz-buzz

html=	dry-fizz-buzz.html \
	dry-fizz-buzz-hom.html \
	dry-fizz-buzz-elf.html \
	trailer.html

blog.html: ${html}
	cat ${html} >blog.html

dry-fizz-buzz-elf: dry-fizz-buzz-elf.c dry-fizz-buzz.c
	gcc ${CFLAGS} -DPTBL='"dry-fizz-buzz-elf.c"' -o dry-fizz-buzz-elf dry-fizz-buzz.c

dry-fizz-buzz-hom: dry-fizz-buzz-hom.c dry-fizz-buzz.c
	gcc ${CFLAGS} -DPTBL='"dry-fizz-buzz-hom.c"' -o dry-fizz-buzz-hom dry-fizz-buzz.c

terse-fizz-buzz: terse-fizz-buzz.c
	gcc ${CFLAGS} -o terse-fizz-buzz terse-fizz-buzz.c

flat-fizz-buzz: flat-fizz-buzz.c
	gcc ${CFLAGS} -o flat-fizz-buzz flat-fizz-buzz.c

checked-fizz-buzz: checked-fizz-buzz.c
	gcc ${CFLAGS} -o checked-fizz-buzz checked-fizz-buzz.c

.SUFFIXES: .html .c

.html.c:
	sed '/^    /!d;s///;s/&lt;/</g' < $< >$@
