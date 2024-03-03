COMPILER = gcc
CSTD = --std=c18

LIB = -I ./lib ./lib/linked_list.o

INCLUDES = ../../CI/objects/queue/queueM.o

PREQ = queue.o

queue: queue.c $(PREQ)
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDES) $(PREQ) -o queue

queue.o: queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c

clean:
	rm -f queue.o queue



