CC = CC -x
OBJ  = Picture.o
OBJ1 = main1.o $(OBJ)
OBJ2 = main2.o $(OBJ)
OBJ3 = main3.o $(OBJ)

Picture.o: Picture.h Picture.c

main1:	$(OBJ1)
	$(CC) $(OBJ1) -omain1

main2:	$(OBJ2)
	$(CC) $(OBJ2) -omain2

main3:	$(OBJ3)
	$(CC) $(OBJ3) -omain3

test:	main1 main2 main3
	main1
	main2
	main3

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) *.ii

clobber:	clean
	rm -f main1 main2 main3

