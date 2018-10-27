CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

#make sure to insert the "unittest4.c unittest5.c" below in unittestresults.out
unittestresults.out: unittest1.c unittest2.c unittest3.c dominion.c rngs.c
	
	echo "Result for running Dominion tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittest1 unittest2 unittest3 unittest4 unittest5 *.gcda *.gcno *.gcov
