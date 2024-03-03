COMPILER = gcc
CSTD = --std=c18
LIB = -I ./lib ./lib/linked_list.o

INCLUDES = ../../CI/objects/stack/stackM.o

PREQ = stack.o

stack: stack.c $(PREQ)
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDES) $(PREQ) -o stack

stack.o: stack.c stack.h
	$(COMPILER) $(CSTD) -c stack.c

clean:
	rm -f stack.o stack
