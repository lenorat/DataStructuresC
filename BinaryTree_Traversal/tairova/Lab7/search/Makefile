COMPILER = gcc
CSTD = --std=c18
LIB = -Ilib
LINKLIST = lib/linked_list.c
STACK = lib/stack.c
QUEUE = lib/queue.c

test: search dfs bfs

search: search.o searchM.o linked_list.o queue.o stack.o
	$(COMPILER) $(CSTD) $(LIB) linked_list.o queue.o stack.o search.o searchM.o -o search

dfs: search.o dfsM.o linked_list.o queue.o stack.o
	$(COMPILER) $(CSTD) $(LIB) linked_list.o queue.o stack.o search.o dfsM.o -o dfs
bfs: search.o bfsM.o linked_list.o queue.o stack.o
	$(COMPILER) $(CSTD) $(LIB) linked_list.o queue.o stack.o search.o bfsM.o -o bfs

search.o: bintree.c bintree.h
	$(COMPILER) $(CSTD) $(LIB) -c bintree.c -o search.o

stack.o: lib/stack.c lib/stack.h
	$(COMPILER) $(CSTD) $(LIB) -c $(STACK) -o stack.o

queue.o: lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) $(LIB) -c $(QUEUE) -o queue.o

linked_list.o: lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) $(LIB) -c $(LINKLIST) -o linked_list.o

clean: 
	rm -f search 
	rm -f dfs 
	rm -f bfs
	rm -f *.o

