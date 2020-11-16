CC = CC -x
OBJ = main.o Expr.o 

Expr.o:	Expr.c Expr.h ../chap25/String.h

main.o:	Expr.h

a.out:	$(OBJ) ../chap25/String.o
	$(CC) $(OBJ) ../chap25/String.o

a.out:	$(OBJ)

test:	a.out
	a.out

clean:
	rm -f $(OBJ) *.ii

clobber:	clean
	rm -f a.out

