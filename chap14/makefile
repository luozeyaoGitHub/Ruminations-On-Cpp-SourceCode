CC = CC -x
OBJ1 = main.o 
OBJ2 = main2.o

main.o: Array.c Array.h

main2.o: Array.c Array.h

main1:	$(OBJ1)
	$(CC) $(OBJ1) -omain1

main2:	$(OBJ2)
	$(CC) $(OBJ2) -omain2

test:	main1 main2
	main1
	main2

clean:
	rm -f $(OBJ1) $(OBJ2) *.ii

clobber:	clean
	rm -f main1 main2

