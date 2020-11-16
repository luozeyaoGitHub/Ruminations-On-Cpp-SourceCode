CC = CC -x
OBJ = main.o 

main.o:	Trace.h

a.out:	$(OBJ)
	$(CC) $(OBJ)

a.out:	$(OBJ)

test:	a.out
	a.out | sort

clean:
	rm -f $(OBJ) *.ii

clobber:	clean
	rm -f a.out

