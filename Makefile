all: dynCGOL cgol

dynCGOL: dynCGOL.o removeSpace.o horizontalBoarder.o horizontalBoarderCounter.o
	gcc -ansi -Wall -o dynCGOL dynCGOL.o removeSpace.o horizontalBoarder.o horizontalBoarderCounter.o

cgol: cgol.o removeSpace.o horizontalBoarder.o horizontalBoarderCounter.o
	gcc -ansi -Wall -o cgol cgol.o removeSpace.o horizontalBoarder.o horizontalBoarderCounter.o

cgol.o:
	gcc -ansi -Wall -c cgol.c

dynCGOL.o:
	gcc -ansi -Wall -c dynCGOL.c

readFile.o:
	gcc -ansi -Wall -c readFile.c

horizontalBoarder.o:
	gcc -ansi -Wall -c horizontalBoarder.c

horizontalBoarderCounter.o:
	gcc -ansi -Wall -c horizontalBoarderCounter.c

removeSpace.o: removeSpace.c 
	gcc -ansi -Wall -c removeSpace.c

testRemoveCommas: testRemoveCommas.o removeCommas.o
	gcc -ansi -Wall -o testRemoveCommas testRemoveCommas.o removeCommas.o

testRemoveCommas.o: testRemoveCommas.c 
	gcc -ansi -Wall -c testRemoveCommas.c

removeCommas.o:
	gcc -ansi -Wall -c removeCommas.c

testConvert: testConvert.o convertLowerCase.o
	gcc -ansi -Wall -o testConvert testConvert.o convertLowerCase.o

testConvert.o: testConvert.c
	gcc -ansi -Wall -c testConvert.c

findWords: findWords.o chop.o convertLowerCase.o replaceDigits.o replacePunc.o reduceSpace.o trim.o
	gcc -ansi -Wall -o findWords findWords.o chop.o convertLowerCase.o replaceDigits.o replacePunc.o reduceSpace.o trim.o

findWords.o: findWords.c
	gcc -ansi -Wall -c findwords.c

chop.o: chop.c
	gcc -ansi -Wall -c chop.c

convertLowerCase.o: convertLowerCase.c
	gcc -ansi -Wall -c convertLowerCase.c

replaceDigits.o: replaceDigits.c
	gcc -ansi -Wall -c replaceDigits.c

replacePunc.o: replacePunc.c
	gcc -ansi -Wall -c replacePunc.c

reduceSpace.o: reduceSpace.c
	gcc -ansi -Wall -c reduceSpace.c

trim.o: trim.c
	gcc -ansi -Wall -c trim.c

clean: 
	rm -f *.o
	rm cgol
	rm dynCGOL
