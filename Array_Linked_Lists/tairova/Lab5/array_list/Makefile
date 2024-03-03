#disccussed during lab
COMPILER = gcc
CSTD = --std=c18


alist_exe: array_list.o arrayM.o
	$(COMPILER) $(CSTD)  array_list.o arrayM.o -o alist_exe

array_list.o: array_list.c array_list.h
	$(COMPILER) $(CSTD) -c array_list.c -o array_list.o

clean:
	rm -f alist_exe
	rm -f array_list.o
