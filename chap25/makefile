CC = CC -x
OBJ = main.o String.o

String.o:	String.c String.h

a.out:	$(OBJ)
	$(CC) $(OBJ)

test:	a.out
	a.out

clean:
	rm -f $(OBJ) *.ii

clobber:	clean
	rm -f a.out

