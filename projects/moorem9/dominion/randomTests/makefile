CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults

#make sure to insert the "unittest4.c unittest5.c" below in unittestresults.out
unittestresults: randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.c rngs.c
	
	echo "Result for running Dominion tests:" >> unittestresults.out
	echo "randomtestcard1.c:" >> unittestresults.out
	gcc -o randomtestcard1 -g dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	echo "randomtestcard2.c:" >> unittestresults.out
	gcc -o randomtestcard2 -g dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "randomtestcard3.c:" >> unittestresults.out
	gcc -o randomtestcard3 -g dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	./randomtestcard3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out


clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out randomtestcard1 randomtestcard2 randomtestcard3 *.gcda *.gcno *.gcov
