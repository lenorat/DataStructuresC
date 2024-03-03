COMPILER = gcc
CSTD = --std=c18
LIB = -Ilib
#location of imported libraries
LINKLIST = lib/linked_list.c
ARRLIST = lib/array_list.c

QUEUE = lib/queue.c
STACK = lib/stack.c

BINTREE = lib/bintree.c

dict: dictionary.o array_list.o bintree.o dictM.o linked_list.o stack.o queue.o
	$(COMPILER) $(CSTD) $(LIB) array_list.o linked_list.o stack.o queue.o bintree.o dictionary.o dictM.o -o dict

#creating obj files

dictionary.o: dictionary.c dictionary.h
	$(COMPILER) $(CSTD) $(LIB) -c dictionary.c -o dictionary.o

array_list.o: lib/array_list.c lib/array_list.h
	$(COMPILER) $(CSTD) $(LIB) -c $(ARRLIST) -o array_list.o

bintree.o: lib/bintree.c lib/bintree.h
	$(COMPILER) $(CSTD) $(LIB) -c $(BINTREE) -o bintree.o

linked_list.o: lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) $(LIB) -c $(LINKLIST) -o linked_list.o

stack.o: lib/stack.c lib/stack.h
	$(COMPILER) $(CSTD) $(LIB) -c $(STACK) -o stack.o

queue.o: lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) $(LIB) -c $(QUEUE) -o queue.o

clean:
	rm -f dict
	rm -f array_list.o
	rm -f bintree.o
	rm -f linked_list.o
	rm -f stack.o
	rm -f queue.o
