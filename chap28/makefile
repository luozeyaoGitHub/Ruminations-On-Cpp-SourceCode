CC = CC -x
OBJ = main.o Cluster.o

Cluster.o:	Cluster.c Cluster.h

a.out:	$(OBJ)
	$(CC) $(OBJ)

test:	a.out
	a.out

clean:
	rm -f $(OBJ) *.ii

clobber:	clean
	rm -f a.out

