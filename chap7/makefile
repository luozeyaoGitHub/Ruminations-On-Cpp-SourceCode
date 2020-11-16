CC = CC -x
OBJ1 = Handle.o
OBJ2 = Handle2.o

Handle.o:	Handle.c Handle.h Point.h

Handle2.o:	Handle2.c Handle2.h Point.h

test:	$(OBJ1) $(OBJ2)

clean:
	rm -f $(OBJ1) $(OBJ2) *.ii

clobber:	clean
	rm -f a.out
