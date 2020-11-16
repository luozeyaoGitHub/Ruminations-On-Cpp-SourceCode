CC = CC -x
OBJ = main.o

main.o:	Seq.h Seq.c

a.out:	$(OBJ) 
	$(CC) $(OBJ)

a.out:	$(OBJ)

test:	a.out
	a.out

clean:
	rm -f $(OBJ) *.ii

clobber:	clean
	rm -f a.out

