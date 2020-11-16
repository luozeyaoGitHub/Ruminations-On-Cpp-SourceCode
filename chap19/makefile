CC = CC -x

OBJ1 = main1.o
OBJ2 = main2.o
OBJ3 = main3.o
OBJ4 = main4.o

main1:	$(OBJ1) copy.h copy.c
	$(CC) $(OBJ1) -omain1

main2:	$(OBJ2) copy.h copy.c Constant_iterator.h Constant_iterator.c
	$(CC) $(OBJ2) -omain2

main3:	$(OBJ3) copy.h copy.c Constant_iterator.h Constant_iterator.c ostream_iterator.h
	$(CC) $(OBJ3) -omain3

main4:	$(OBJ4) copy.h copy.c ostream_iterator.h istream_iterator.h
	$(CC) $(OBJ4) -omain4

test:	main1 main2 main3 main4
	main1
	main2
	main3
	main4 <input_file

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) *.ii

clobber:	clean
	rm -f main1 main2 main3 main4

