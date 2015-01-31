LEX=lex
YACC=yacc
CFLAGS=-Wall -O0 -g
CC=gcc

all: parser

parser:parser.c scanner.c table.c
	$(CC) $(CFLAGS) -o $@ $^

parser.c:parser.y
	$(YACC) -o $@ --defines=parser.tab.h $^

%.c:%.l
	$(LEX) -o $@ $^

tests:
	for i in `ls ../tst/*.c`; do echo $$i; ./parser $$i; done

tests_barthou:
	for i in `ls ../tests/*.c`; do echo $$i; ./parser $$i; done

gcc:
	for i in `ls ../tst/*.c`; do echo $$i; $(CC) $$i; done

gcc_barthou:
	for i in `ls ../tests/*.c`; do echo $$i; $(CC) $$i; done

clean:
	rm -f parser.c parser.tab.h parser.tab.c scanner.c ../tst/*.s ../tests/*.s a.out
