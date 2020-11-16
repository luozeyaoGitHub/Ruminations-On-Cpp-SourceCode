CC = CC -x
OBJ1 = main1.o 
OBJ2 = main2.o
OBJ3 = main3.o
OBJ4 = main4.o
OBJ5 = main5.o
OBJ6 = main6.o
OBJR = main_Reader.o

main1:	$(OBJ1)
	$(CC) $(OBJ1) -omain1

main2:	$(OBJ2) Int_iterator.h
	$(CC) $(OBJ2) -omain2

main3:	$(OBJ3) Iterator.h
	$(CC) $(OBJ3) -omain3

main4:	$(OBJ4) Iterator.h
	$(CC) $(OBJ4) -omain4

main5:	$(OBJ5) Iterator.h
	$(CC) $(OBJ5) -omain5

main6:	$(OBJ6) Iterator.h
	$(CC) $(OBJ6) -omain6

mainR:	$(OBJR) Reader.h
	$(CC) $(OBJR) -omainR

test:	main1 main2 main3 main4 main5 main6 mainR
	main1
	main2
	main3
	main4
	main5
	main6
	mainR <input_file

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJR) *.ii

clobber:	clean
	rm -f main1 main2 main3 main4 main5 main6 mainR

