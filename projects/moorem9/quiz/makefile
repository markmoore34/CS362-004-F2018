CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: quizResults.out

quizResults.out: testme.c

	echo "testing making the .out file" >> quizResults.out
	gcc -o testme -g testme.c $(CFLAGS)
	./testme
	gcov -stdout testme.c

clean:
	rm quizResults.out

cleanall: 
	rm quizResults.out testme *.gcda *.gcno *.gcov
