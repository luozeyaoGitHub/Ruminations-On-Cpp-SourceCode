CC = CC -x
OBJ = main.o 

main.o: Array.h Array.c

a.out:	$(OBJ) 
	$(CC) $(OBJ)

test:	a.out
	a.out

clean:
	rm -f $(OBJ) *.ii

clobber:	clean
	rm -f a.out

