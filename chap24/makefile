CC = CC -x
OBJ = main.o dirlib.o 

dirlib.o:	dirlib.c dirlib.h 

main.o:	dirlib.h

a.out:	$(OBJ) 
	$(CC) $(OBJ) 

a.out:	$(OBJ)

test:	a.out
	a.out

clean:
	rm -f $(OBJ) *.ii

clobber:	clean
	rm -f a.out

